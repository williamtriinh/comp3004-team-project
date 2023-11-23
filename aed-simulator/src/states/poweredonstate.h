#ifndef POWEREDONSTATE_H
#define POWEREDONSTATE_H

#include "basestate.h"

class PoweredOnState : public BaseState
{
public:
    PoweredOnState();
    void execute() override;
    void togglePower() override;
};

#endif // POWEREDONSTATE_H
