#include "selfteststate.h"

#include "../mainwindow.h"
#include "checkresponsivenessstate.h"

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
    // Pretend the self test takes 3 seconds to complete
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

QString SelfTestState::getStateName()
{
    return "SelfTestState";
}
