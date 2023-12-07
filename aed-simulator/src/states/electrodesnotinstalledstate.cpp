#include "electrodesnotinstalledstate.h"

#include "../mainwindow.h"

ElectrodesNotInstalledState::ElectrodesNotInstalledState(MainWindow *context)
    : BaseState(context)
{
}

void ElectrodesNotInstalledState::initialize()
{
    context->playMessage("Attach electrode pads.");
    context->resetECGDisplay();
}

QString ElectrodesNotInstalledState::getStateName()
{
    return "ElectrodesNotInstalledState";
}
