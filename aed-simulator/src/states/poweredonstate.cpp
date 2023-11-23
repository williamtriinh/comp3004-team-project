#include "poweredonstate.h"

#include "../mainwindow.h"
#include "selfteststate.h"

#include <QDebug>

PoweredOnState::PoweredOnState()
{

}

void PoweredOnState::execute() {
    context->changeState(new SelfTestState);
}

void PoweredOnState::togglePower() {

}
