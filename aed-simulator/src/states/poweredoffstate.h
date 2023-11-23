#ifndef POWEREDOFFSTATE_H
#define POWEREDOFFSTATE_H

#include "basestate.h"

class PoweredOffState : public BaseState
{
public:
    PoweredOffState();
    void execute() override;
    void togglePower() override;
};

#endif // POWEREDOFFSTATE_H
