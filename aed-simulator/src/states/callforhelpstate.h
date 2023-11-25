#ifndef CALLFORHELPSTATE_H
#define CALLFORHELPSTATE_H

#include "basestate.h"

#include <QTimer>

class CallForHelpState : public BaseState
{
public:
    CallForHelpState(MainWindow *context);
    ~CallForHelpState() override;
    void initialize() override;
    QString getStateName() override;

public slots:
    void execute() override;

private:
    QTimer *timer;
};

#endif // CALLFORHELPSTATE_H
