#include "callforhelpstate.h"

CallForHelpState::CallForHelpState(MainWindow *context)
    : BaseState(context)
{
}

CallForHelpState::~CallForHelpState()
{
}

void CallForHelpState::execute()
{
}

void CallForHelpState::togglePower()
{
}

QString CallForHelpState::getStateName()
{
    return "CallForHelpState";
}
