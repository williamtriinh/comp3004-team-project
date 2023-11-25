#include "analyzingstate.h"

AnalyzingState::AnalyzingState(MainWindow *context)
    : BaseState(context)
{
}

AnalyzingState::~AnalyzingState()
{
}

void AnalyzingState::execute()
{
}

void AnalyzingState::togglePower()
{
}

QString AnalyzingState::getStateName()
{
    return "AnalyzingState";
}
