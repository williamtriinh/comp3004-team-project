#ifndef CHECKRESPONSIVENESSSTATE_H
#define CHECKRESPONSIVENESSSTATE_H

#include "basestate.h"

class CheckResponsivenessState : public BaseState
{
public:
    CheckResponsivenessState();
    void execute() override;
    void togglePower() override;
};

#endif // CHECKRESPONSIVENESSSTATE_H
