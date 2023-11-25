#ifndef POWEREDONSTATE_H
#define POWEREDONSTATE_H

#include "basestate.h"

class PoweredOnState : public BaseState
{
public:
    PoweredOnState(MainWindow *context);
    void initialize() override;
    void togglePower() override;
    QString getStateName() override;
};

#endif // POWEREDONSTATE_H
