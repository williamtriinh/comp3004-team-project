#include "poweredonstate.h"

#include <QDebug>

PoweredOnState::PoweredOnState()
{

}

void PoweredOnState::execute() {
    qDebug() << "Executing PoweredOnState";
}

void PoweredOnState::togglePower() {

}
