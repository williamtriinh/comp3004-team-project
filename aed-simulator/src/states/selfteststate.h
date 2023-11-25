#ifndef SELFTESTSTATE_H
#define SELFTESTSTATE_H

#include "../utils/intermediatestate.h"
#include "basestate.h"

#include <QTimer>

class SelfTestState : public BaseState, public IntermediateState
{
public:
    static const int SELF_TEST_DURATION_MS = 3000;

    SelfTestState(MainWindow *context);
    ~SelfTestState();
    void initialize() override;
    QString getStateName() override;

public slots:
    void execute() override;

private:
    QTimer *timer;
};

#endif // SELFTESTSTATE_H
