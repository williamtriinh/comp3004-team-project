#ifndef CHECKRESPONSIVENESSSTATE_H
#define CHECKRESPONSIVENESSSTATE_H

#include "basestate.h"

class CheckResponsivenessState : public BaseState
{
public:
    CheckResponsivenessState(MainWindow *context);
    void execute() override;
    QString getStateName() override;
};

#endif // CHECKRESPONSIVENESSSTATE_H
