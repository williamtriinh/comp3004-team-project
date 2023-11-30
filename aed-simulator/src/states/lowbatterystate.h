#ifndef LOWBATTERYSTATE_H
#define LOWBATTERYSTATE_H

#include "basestate.h"

class LowBatteryState : public BaseState
{
public:
    LowBatteryState(MainWindow *context);
    void initialize() override;
    QString getStateName() override;
};

#endif // LOWBATTERYSTATE_H
