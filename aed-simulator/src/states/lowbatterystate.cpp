#include "lowbatterystate.h"

#include "../mainwindow.h"

LowBatteryState::LowBatteryState(MainWindow *context)
    : BaseState(context)
{
}

void LowBatteryState::initialize()
{
    context->playMessage("Change batteries.");
}

QString LowBatteryState::getStateName()
{
    return "LowBatteryState";
}
