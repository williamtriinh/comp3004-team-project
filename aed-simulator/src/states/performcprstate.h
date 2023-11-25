#ifndef PERFORMCPRSTATE_H
#define PERFORMCPRSTATE_H

#include "basestate.h"

class PerformCPRState : public BaseState
{
public:
    PerformCPRState(MainWindow *context);
    ~PerformCPRState() override;
    QString getStateName() override;

public slots:
    void execute() override;
    void togglePower() override;
};

#endif // PERFORMCPRSTATE_H
