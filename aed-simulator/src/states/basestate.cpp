#include "basestate.h"

#include <QDebug>

BaseState::BaseState(MainWindow *context)
{
    this->context = context;
}

BaseState::~BaseState()
{
    // Optional
}

void BaseState::initialize()
{
    // Optional
}

void BaseState::execute()
{
    qDebug() << "TODO: Implement execute()";
}

void BaseState::togglePower()
{
    qDebug() << "TODO: Implement togglePower()";
}
