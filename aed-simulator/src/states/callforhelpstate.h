#ifndef CALLFORHELPSTATE_H
#define CALLFORHELPSTATE_H

#include "basestate.h"

class CallForHelpState : public BaseState
{
public:
    CallForHelpState(MainWindow *context);
    ~CallForHelpState() override;
    QString getStateName() override;

public slots:
    void execute() override;
    void togglePower() override;
};

#endif // CALLFORHELPSTATE_H
