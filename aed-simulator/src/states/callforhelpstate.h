#ifndef CALLFORHELPSTATE_H
#define CALLFORHELPSTATE_H

#include "basestate.h"

class CallForHelpState : public BaseState
{
public:
    CallForHelpState(MainWindow *context);
    ~CallForHelpState() override;
    void execute() override;
    void togglePower() override;
    QString getStateName() override;
};

#endif // CALLFORHELPSTATE_H
