#include "checkresponsivenessstate.h"

#include "../mainwindow.h"

CheckResponsivenessState::CheckResponsivenessState(MainWindow *context)
    : BaseState(context)
{
}

void CheckResponsivenessState::execute()
{
}

QString CheckResponsivenessState::getStateName()
{
    return "CheckResponsivenessState";
}
