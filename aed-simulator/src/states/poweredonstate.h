#ifndef POWEREDONSTATE_H
#define POWEREDONSTATE_H

#include "basestate.h"

class PoweredOnState : public BaseState
{
public:
    PoweredOnState(MainWindow *context);
    void initialize() override;
    QString getStateName() override;

public slots:
    void togglePower() override;
};

#endif // POWEREDONSTATE_H
