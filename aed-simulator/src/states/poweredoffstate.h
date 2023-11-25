#ifndef POWEREDOFFSTATE_H
#define POWEREDOFFSTATE_H

#include "basestate.h"

class PoweredOffState : public BaseState
{
public:
    PoweredOffState(MainWindow *context);
    void initialize() override;
    QString getStateName() override;

public slots:
    void togglePower() override;
};

#endif // POWEREDOFFSTATE_H
