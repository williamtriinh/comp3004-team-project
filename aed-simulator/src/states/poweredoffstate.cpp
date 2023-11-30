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
    qDebug() << "!!!!!!";
    context->resetElapsedTime();
}

void PoweredOffState::togglePower()
{
    context->changeState(new PoweredOnState(context));
    context->startElapsedTime();
}

QString PoweredOffState::getStateName()
{
    return "PoweredOffState";
}
