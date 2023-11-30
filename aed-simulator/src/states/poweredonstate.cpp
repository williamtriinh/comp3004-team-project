#include "poweredonstate.h"

#include "../mainwindow.h"
#include "poweredoffstate.h"
#include "selfteststate.h"

PoweredOnState::PoweredOnState(MainWindow *context)
    : BaseState(context)
{
}

void PoweredOnState::initialize()
{
    context->changeState(new SelfTestState(context));
}

void PoweredOnState::togglePower()
{
    context->changeState(new PoweredOffState(context));
}

QString PoweredOnState::getStateName()
{
    return "PoweredOnState";
}
