#include "poweredoffstate.h"

#include "../mainwindow.h"
#include "poweredonstate.h"

PoweredOffState::PoweredOffState(MainWindow *context)
    : BaseState(context)
{



    timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, &QTimer::timeout, this, &PoweredOffState::execute);
}

PoweredOffState::~PoweredOffState()
{
    delete timer;

}

void PoweredOffState::initialize()
{
    context->playMessage("Powering off.");
    context->setUnitStatus(MainWindow::UnitStatus::DEFAULT);
    context->stopTimer();
    execute();
}

void PoweredOffState::execute()
{
    if (!context->hasSufficientBattery())
    {
        context->playMessage("*Beep*");
    }
    timer->start(2000);
}

void PoweredOffState::togglePower()
{

    context->startTimer();
    context->changeState(new PoweredOnState(context));
    if (context->getBattery() > 0)
        context->changeState(new PoweredOnState(context));
}

QString PoweredOffState::getStateName()
{
    return "PoweredOffState";
}
