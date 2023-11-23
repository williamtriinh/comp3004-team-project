#ifndef ATTACHDEFIBRILLATORPADSSTATE_H
#define ATTACHDEFIBRILLATORPADSSTATE_H

#include "basestate.h"

class AttachDefibrillatorPadsState : public BaseState
{
public:
    AttachDefibrillatorPadsState();
    void execute() override;
    void togglePower() override;
};

#endif // ATTACHDEFIBRILLATORPADSSTATE_H
