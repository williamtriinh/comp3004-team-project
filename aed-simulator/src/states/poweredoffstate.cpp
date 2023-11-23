#include "poweredoffstate.h"

#include "../mainwindow.h"
#include "poweredonstate.h"

PoweredOffState::PoweredOffState() {
}

void PoweredOffState::execute() {
}

void PoweredOffState::togglePower() {
    context->changeState(new PoweredOnState);
}
