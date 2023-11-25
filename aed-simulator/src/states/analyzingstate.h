#ifndef ANALYZINGSTATE_H
#define ANALYZINGSTATE_H

#include "basestate.h"

class AnalyzingState : public BaseState
{
public:
    AnalyzingState(MainWindow *context);
    ~AnalyzingState() override;
    void initialize() override;
    QString getStateName() override;

public slots:
    void execute() override;
};

#endif // ANALYZINGSTATE_H
