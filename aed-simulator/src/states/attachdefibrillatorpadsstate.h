#ifndef ATTACHDEFIBRILLATORPADSSTATE_H
#define ATTACHDEFIBRILLATORPADSSTATE_H

#include "basestate.h"

class AttachDefibrillatorPadsState : public BaseState
{
public:
    AttachDefibrillatorPadsState(MainWindow *context);
    ~AttachDefibrillatorPadsState() override;
    QString getStateName() override;

public slots:
    void execute() override;
};

#endif // ATTACHDEFIBRILLATORPADSSTATE_H
