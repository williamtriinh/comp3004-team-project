#include "checkresponsivenessstate.h"

#include "../mainwindow.h"
#include "callforhelpstate.h"

CheckResponsivenessState::CheckResponsivenessState(MainWindow *context)
    : BaseState(context)
{
    timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, &QTimer::timeout, this, &CheckResponsivenessState::execute);
}

CheckResponsivenessState::~CheckResponsivenessState()
{
    delete timer;
}

void CheckResponsivenessState::initialize()
{
    context->playMessage("Check responsiveness.");
    timer->start(5000);
}

void CheckResponsivenessState::execute()
{
    context->changeState(new CallForHelpState(context));
}

QString CheckResponsivenessState::getStateName()
{
    return "CheckResponsivenessState";
}
