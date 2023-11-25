#include "performcprstate.h"

PerformCPRState::PerformCPRState(MainWindow *context)
    : BaseState(context)
{
}

PerformCPRState::~PerformCPRState()
{
}

void PerformCPRState::execute()
{
}

void PerformCPRState::togglePower()
{
}

QString PerformCPRState::getStateName()
{
    return "PerformCPRState";
}
