#include "selfteststate.h"

#include "../mainwindow.h"
#include "checkresponsivenessstate.h"
#include "poweredoffstate.h"

SelfTestState::SelfTestState(MainWindow *context)
    : BaseState(context)
{
    timer->start(3000);
}

void SelfTestState::execute()
{
    if (context->getBattery() < 70 || !context->getElectrodesInstalled()) {
        context->setUnitStatus(MainWindow::UnitStatus::FAILED);
        return;
    }
    context->setUnitStatus(MainWindow::UnitStatus::OK);
    context->playMessage("UNIT OK");
    context->changeState(new CheckResponsivenessState(context));
}

void SelfTestState::togglePower()
{
    context->changeState(new PoweredOffState(context));
}
