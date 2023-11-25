#include "analyzingstate.h"
#include "../mainwindow.h"

AnalyzingState::AnalyzingState(MainWindow *context)
    : BaseState(context)
{
    timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, &QTimer::timeout, this, &AnalyzingState::execute);
}

AnalyzingState::~AnalyzingState()
{
}

void AnalyzingState::execute()
{
}

void AnalyzingState::initialize(){
    context->playMessage("Don't touch patient. Analyzing");
}

QString AnalyzingState::getStateName()
{
    return "AnalyzingState";
}
