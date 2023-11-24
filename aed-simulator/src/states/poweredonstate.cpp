#include "poweredonstate.h"

#include "../mainwindow.h"
#include "selfteststate.h"

#include <QDebug>

PoweredOnState::PoweredOnState(MainWindow *context)
    : BaseState(context)
{
}

void PoweredOnState::execute()
{
    context->changeState(new SelfTestState(context));
}

void PoweredOnState::togglePower()
{
}
