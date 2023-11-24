#ifndef ANALYZINGSTATE_H
#define ANALYZINGSTATE_H

#include "basestate.h"

class AnalyzingState : public BaseState
{
public:
    AnalyzingState(MainWindow *context);
    ~AnalyzingState() override;
    void execute() override;
    void togglePower() override;
    QString getStateName() override;
};

#endif // ANALYZINGSTATE_H
