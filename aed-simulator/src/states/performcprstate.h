#ifndef PERFORMCPRSTATE_H
#define PERFORMCPRSTATE_H

#include "basestate.h"

class PerformCPRState : public BaseState
{
public:
    PerformCPRState(MainWindow *context);
    ~PerformCPRState() override;
    void execute() override;
    void togglePower() override;
    QString getStateName() override;
};

#endif // PERFORMCPRSTATE_H
