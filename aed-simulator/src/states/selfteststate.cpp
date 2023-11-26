#include "selfteststate.h"

#include "../mainwindow.h"
#include "checkresponsivenessstate.h"

SelfTestState::SelfTestState(MainWindow *context)
    : BaseState(context)
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
    // Pretend the self-test takes SELF_TEST_DURATION_MS milliseconds to complete
    timer->start(SELF_TEST_DURATION_MS);
}

void SelfTestState::execute()
{

    switch (getStep())
    {
    case 0:
    {
        if (context->getBattery() < 70)
        {
            context->setUnitStatus(MainWindow::UnitStatus::FAILED);
            context->playMessage("Change batteries.");
            return;
        }

        if (!context->getElectrodesInstalled())
        {
            context->setUnitStatus(MainWindow::UnitStatus::FAILED);
            context->playMessage("Attach electrode pads.");
            return;
        }

        context->setUnitStatus(MainWindow::UnitStatus::OK);
        context->playMessage("Automatic defibrillator unit OK.");
        timer->start(SPEECH_DELAY_MS);
        break;
    }
    case 1:
        context->playMessage("Stay calm.");
        timer->start(SPEECH_DELAY_MS);
        break;
    case 2:
        context->changeState(new CheckResponsivenessState(context));
        return;
    }
    nextStep();
}

QString SelfTestState::getStateName()
{
    return "SelfTestState";
}
