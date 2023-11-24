#ifndef SELFTESTSTATE_H
#define SELFTESTSTATE_H

#include "basestate.h"

#include <QObject>
#include <QTimer>

class SelfTestState : public QObject, public BaseState
{
    Q_OBJECT
public:
    SelfTestState(MainWindow *context);
    ~SelfTestState() override;
    void initialize() override;
    QString getStateName() override;

public slots:
    void execute() override;
    void togglePower() override;

private:
    QTimer *timer;
};

#endif // SELFTESTSTATE_H
