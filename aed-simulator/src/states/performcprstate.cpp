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

QString PerformCPRState::getStateName()
{
    return "PerformCPRState";
}
