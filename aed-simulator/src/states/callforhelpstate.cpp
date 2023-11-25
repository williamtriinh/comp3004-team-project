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

QString CallForHelpState::getStateName()
{
    return "CallForHelpState";
}
