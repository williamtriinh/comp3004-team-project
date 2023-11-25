#ifndef CHECKRESPONSIVENESSSTATE_H
#define CHECKRESPONSIVENESSSTATE_H

#include "basestate.h"

class CheckResponsivenessState : public BaseState
{
public:
    CheckResponsivenessState(MainWindow *context);
    QString getStateName() override;

public slots:
    void execute() override;
};

#endif // CHECKRESPONSIVENESSSTATE_H
