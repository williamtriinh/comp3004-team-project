#include "basestate.h"

#include "../mainwindow.h"
#include "poweredoffstate.h"

#include <QDebug>

BaseState::BaseState(MainWindow *context)
    : QObject(context)
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
    context->changeState(new PoweredOffState(context));
}
