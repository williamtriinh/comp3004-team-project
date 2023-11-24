#include "poweredoffstate.h"

#include "../mainwindow.h"
#include "poweredonstate.h"

PoweredOffState::PoweredOffState(MainWindow *context)
    : BaseState(context)
{
}

void PoweredOffState::execute()
{
}

void PoweredOffState::togglePower() {
    context->changeState(new PoweredOnState(context));
}
