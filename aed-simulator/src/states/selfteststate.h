#ifndef SELFTESTSTATE_H
#define SELFTESTSTATE_H

#include "basestate.h"

class SelfTestState : public BaseState
{
public:
    SelfTestState();
    void execute() override;
    void togglePower() override;
};

#endif // SELFTESTSTATE_H
