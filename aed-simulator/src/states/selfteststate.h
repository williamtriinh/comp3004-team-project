#ifndef SELFTESTSTATE_H
#define SELFTESTSTATE_H

#include "basestate.h"

#include <QTimer>

class SelfTestState : public BaseState
{
public:
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
