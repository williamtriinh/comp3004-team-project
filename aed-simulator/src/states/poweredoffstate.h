#ifndef POWEREDOFFSTATE_H
#define POWEREDOFFSTATE_H

#include "basestate.h"

#include <QTimer>

class PoweredOffState : public BaseState
{
public:
    PoweredOffState(MainWindow *context);
    ~PoweredOffState();
    void initialize() override;
    QString getStateName() override;

public slots:
    void execute() override;
    void togglePower() override;

private:
    QTimer *timer;

};

#endif // POWEREDOFFSTATE_H
