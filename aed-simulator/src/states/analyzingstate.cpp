#include "analyzingstate.h"

#include "../mainwindow.h"

AnalyzingState::AnalyzingState(MainWindow *context)
    : BaseState(context)
{
}

AnalyzingState::~AnalyzingState()
{
}

void AnalyzingState::initialize()
{
    context->playMessage("Don't touch patient. Analyzing.");
}

void AnalyzingState::execute()
{
}

QString AnalyzingState::getStateName()
{
    return "AnalyzingState";
}
