#ifndef ANALYZINGSTATE_H
#define ANALYZINGSTATE_H

#include "basestate.h"
#include "../utils/intermediatestate.h"
#include <QTimer>

class AnalyzingState : public BaseState, public IntermediateState
{
public:
    static const int SELF_TEST_DURATION_MS = 5000;
    AnalyzingState(MainWindow *context);
    ~AnalyzingState() override;
    void initialize() override;
    QString getStateName() override;



public slots:
    void execute() override;


private:
    QTimer *timer;

};

#endif // ANALYZINGSTATE_H
