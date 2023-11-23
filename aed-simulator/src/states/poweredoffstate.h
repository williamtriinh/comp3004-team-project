#ifndef POWEREDOFFSTATE_H
#define POWEREDOFFSTATE_H

#include "aedstateinterface.h"

class PoweredOffState : public AEDStateInterface
{
public:
    PoweredOffState();
    void execute() override;
    void togglePower() override;
};

#endif // POWEREDOFFSTATE_H
