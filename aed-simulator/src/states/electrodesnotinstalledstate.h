#ifndef ELECTRODESNOTINSTALLEDSTATE_H
#define ELECTRODESNOTINSTALLEDSTATE_H

#include "basestate.h"

class MainWindow;

class ElectrodesNotInstalledState : public BaseState
{
public:
    ElectrodesNotInstalledState(MainWindow *context);
    void initialize() override;
    QString getStateName() override;
};

#endif // ELECTRODESNOTINSTALLEDSTATE_H
