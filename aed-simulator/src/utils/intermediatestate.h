#ifndef INTERMEDIATESTATE_H
#define INTERMEDIATESTATE_H

/**
 * Abstract class that adds intermediate steps to the states. ALlows for more intricate
 * functionality.
 */
class IntermediateState
{
public:
    IntermediateState();

    virtual void nextStep();

    virtual int getStep();

    virtual void setStep(int step);

private:
    int step = 0;
};

#endif // INTERMEDIATESTATE_H
