#ifndef ANALYZINGSTATE_H
#define ANALYZINGSTATE_H

#include "basestate.h"

class AnalyzingState : public BaseState
{
public:
    AnalyzingState(MainWindow *context);
    ~AnalyzingState() override;
    QString getStateName() override;

public slots:
    void execute() override;
    void togglePower() override;
};

#endif // ANALYZINGSTATE_H
