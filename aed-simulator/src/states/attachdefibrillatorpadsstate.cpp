#include "attachdefibrillatorpadsstate.h"

#include "../mainwindow.h"
#include "analyzingstate.h"

AttachDefibrillatorPadsState::AttachDefibrillatorPadsState(MainWindow *context)
    : BaseState(context)
{
    timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, &QTimer::timeout, this, &AttachDefibrillatorPadsState::execute);
}

AttachDefibrillatorPadsState::~AttachDefibrillatorPadsState()
{
    delete timer;
}

void AttachDefibrillatorPadsState::initialize()
{
    context->playMessage("Attach defib pads to patient's bare chest.");
    timer->start(POLL_INTERVAL_MS);
}

void AttachDefibrillatorPadsState::execute()
{
    if (context->getElectrodePadsAttachedState() != MainWindow::ElectrodePadsAttachedState::ATTACHED_SUCCESSFULLY)
    {
        timer->start(POLL_INTERVAL_MS);
        return;
    }
    context->changeState(new AnalyzingState(context));
}

QString AttachDefibrillatorPadsState::getStateName()
{
    return "AttachDefibrillatorPadsState";
}
