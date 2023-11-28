#include "poweredoffstate.h"

#include "../mainwindow.h"
#include "poweredonstate.h"

PoweredOffState::PoweredOffState(MainWindow *context)
    : BaseState(context)
{
}

void PoweredOffState::initialize()
{
    context->playMessage("Powering off.");
    context->setUnitStatus(MainWindow::UnitStatus::DEFAULT);
}

void PoweredOffState::togglePower()
{
    context->changeState(new PoweredOnState(context));
}

QString PoweredOffState::getStateName()
{
    return "PoweredOffState";
}
