#include "selfteststate.h"

#include "../mainwindow.h"
#include "poweredoffstate.h"

SelfTestState::SelfTestState()
{

}

void SelfTestState::execute() {

}

void SelfTestState::togglePower() {
    context->changeState(new PoweredOffState);
}
