#ifndef ANALYZINGSTATE_H
#define ANALYZINGSTATE_H

#include "basestate.h"
#include <QTimer>

class AnalyzingState : public BaseState
{
public:
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
