#include "checkresponsivenessstate.h"

#include "../mainwindow.h"
#include "poweredoffstate.h"

CheckResponsivenessState::CheckResponsivenessState(MainWindow *context)
    : BaseState(context)
{
}

void CheckResponsivenessState::execute()
{
}

void CheckResponsivenessState::togglePower()
{
    context->changeState(new PoweredOffState(context));
}

QString CheckResponsivenessState::getStateName()
{
    return "CheckResponsivenessState";
}
