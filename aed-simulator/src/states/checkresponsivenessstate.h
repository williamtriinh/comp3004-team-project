#ifndef CHECKRESPONSIVENESSSTATE_H
#define CHECKRESPONSIVENESSSTATE_H

#include "basestate.h"

#include <QTimer>

class CheckResponsivenessState : public BaseState
{
public:
    CheckResponsivenessState(MainWindow *context);
    ~CheckResponsivenessState();
    void initialize() override;
    QString getStateName() override;

public slots:
    void execute() override;

private:
    QTimer *timer;
};

#endif // CHECKRESPONSIVENESSSTATE_H
