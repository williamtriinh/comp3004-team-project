#ifndef ANALYZINGSTATE_H
#define ANALYZINGSTATE_H

#include "basestate.h"

class AnalyzingState : public BaseState
{
public:
    AnalyzingState();
    void execute() override;
    void togglePower() override;
};

#endif // ANALYZINGSTATE_H
