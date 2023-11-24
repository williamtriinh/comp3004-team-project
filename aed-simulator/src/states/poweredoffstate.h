#ifndef POWEREDOFFSTATE_H
#define POWEREDOFFSTATE_H

#include "basestate.h"

#include <QObject>

class PoweredOffState : public BaseState
{
public:
    PoweredOffState(MainWindow *context);
    void initialize() override;
    void togglePower() override;
    QString getStateName() override;
};

#endif // POWEREDOFFSTATE_H
