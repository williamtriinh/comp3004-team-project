#include "basestate.h"

#include <QDebug>

BaseState::BaseState(MainWindow *context) {
    this->context = context;
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &BaseState::execute);
}

BaseState::~BaseState() {
    delete timer;
}
