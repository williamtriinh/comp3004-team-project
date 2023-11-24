#ifndef ATTACHDEFIBRILLATORPADSSTATE_H
#define ATTACHDEFIBRILLATORPADSSTATE_H

#include "basestate.h"

class AttachDefibrillatorPadsState : public BaseState
{
public:
    AttachDefibrillatorPadsState(MainWindow *context);
    ~AttachDefibrillatorPadsState() override;
    void execute() override;
    void togglePower() override;
    QString getStateName() override;
};

#endif // ATTACHDEFIBRILLATORPADSSTATE_H
