#ifndef ATTACHDEFIBRILLATORPADSSTATE_H
#define ATTACHDEFIBRILLATORPADSSTATE_H

#include "basestate.h"

#include <QTimer>

class AttachDefibrillatorPadsState : public BaseState
{
public:
    static const int POLL_INTERVAL_MS = 2000;

    AttachDefibrillatorPadsState(MainWindow *context);
    ~AttachDefibrillatorPadsState() override;
    void initialize() override;
    QString getStateName() override;

public slots:
    void execute() override;

private:
    QTimer *timer;
};

#endif // ATTACHDEFIBRILLATORPADSSTATE_H
