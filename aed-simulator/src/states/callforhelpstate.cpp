#include "callforhelpstate.h"

#include "../mainwindow.h"
#include "attachdefibrillatorpadsstate.h"

CallForHelpState::CallForHelpState(MainWindow *context)
    : BaseState(context)
{
    timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, &QTimer::timeout, this, &CallForHelpState::execute);
}

CallForHelpState::~CallForHelpState()
{
    delete timer;
}

void CallForHelpState::initialize()
{
    context->playMessage("Call for help.");
    timer->start(5000);
}

void CallForHelpState::execute()
{
    context->changeState(new AttachDefibrillatorPadsState(context));
}

QString CallForHelpState::getStateName()
{
    return "CallForHelpState";
}
