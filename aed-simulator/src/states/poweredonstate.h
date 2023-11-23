#ifndef POWEREDONSTATE_H
#define POWEREDONSTATE_H

#include "aedstateinterface.h"

class PoweredOnState : public AEDStateInterface
{
public:
    PoweredOnState();
    void execute() override;
    void togglePower() override;
};

#endif // POWEREDONSTATE_H
