#include "performcprstate.h"
#include "../mainwindow.h"
#include "analyzingstate.h"

PerformCPRState::PerformCPRState(MainWindow *context)
    : BaseState(context)
{
    timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, &QTimer::timeout, this, &PerformCPRState::execute);
}

PerformCPRState::~PerformCPRState()
{
    delete timer;
}

void PerformCPRState::initialize()
{
    context->playMessage("Perform CPR.");
    timer->start(2000);
}

void PerformCPRState::execute()
{



    switch (getStep()) {
        case 0:
            context->playMessage("Compression too deep. Reduce force.");
            timer->start(2000);
            break;

        case 1:
            context->playMessage("Compression too shallow. Press harder.");
            timer->start(2000);
            break;

        case 2:
            context->playMessage("Good compression depth. Keep going.");
            timer->start(2000);
            break;

        case 3:
            context->changeState(new AnalyzingState(context));
            return;
    }
    nextStep();



}

QString PerformCPRState::getStateName()
{
    return "PerformCPRState";
}
