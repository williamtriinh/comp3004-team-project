#ifndef PERFORMCPRSTATE_H
#define PERFORMCPRSTATE_H

#include "basestate.h"

class PerformCPRState : public BaseState
{
public:
    PerformCPRState();
    void execute() override;
    void togglePower() override;
};

#endif // PERFORMCPRSTATE_H
