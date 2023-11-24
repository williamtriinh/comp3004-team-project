#include "selfteststate.h"

#include "../mainwindow.h"
#include "checkresponsivenessstate.h"
#include "poweredoffstate.h"

#include <QDebug>

SelfTestState::SelfTestState(MainWindow *context)
    : QObject(context), BaseState(context)
{
    timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, &QTimer::timeout, this, &SelfTestState::execute);
}

SelfTestState::~SelfTestState()
{
    delete timer;
}

void SelfTestState::initialize()
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

QString SelfTestState::getStateName()
{
    return "SelfTestState";
}
