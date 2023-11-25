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

QString AnalyzingState::getStateName()
{
    return "AnalyzingState";
}
