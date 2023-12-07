#ifndef PERFORMCPRSTATE_H
#define PERFORMCPRSTATE_H

#include "basestate.h"
#include "../utils/intermediatestate.h"
#include <QTimer>

class PerformCPRState : public BaseState, public IntermediateState
{
public:
    PerformCPRState(MainWindow *context);
    ~PerformCPRState() override;
    void initialize() override;
    QString getStateName() override;

public slots:
    void execute() override;

private:
    QTimer *timer;
};

#endif // PERFORMCPRSTATE_H
