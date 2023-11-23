#include "poweredoffstate.h"

#include "../mainwindow.h"
#include "poweredonstate.h"

#include <QDebug>

PoweredOffState::PoweredOffState() {
}

void PoweredOffState::execute() {
    qDebug() << "Executing PoweredOffState";
}

void PoweredOffState::togglePower() {
    qDebug() << "Powered Off State: togglePower";
    context->changeState(new PoweredOnState);
}
