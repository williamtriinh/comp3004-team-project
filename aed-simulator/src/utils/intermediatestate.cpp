#include "intermediatestate.h"

#include <algorithm>

IntermediateState::IntermediateState()
{
    step = 0;
}

void IntermediateState::nextStep()
{
    step += 1;
}

int IntermediateState::getStep()
{
    return step;
}

void IntermediateState::setStep(int step)
{
    this->step = std::max(step, 0);
}
