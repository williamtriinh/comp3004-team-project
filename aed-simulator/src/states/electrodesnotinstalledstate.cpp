#include "electrodesnotinstalledstate.h"

#include "../mainwindow.h"

ElectrodesNotInstalledState::ElectrodesNotInstalledState(MainWindow *context)
    : BaseState(context)
{
}

void ElectrodesNotInstalledState::initialize()
{
    context->playMessage("Attach electrode pads.");
}

QString ElectrodesNotInstalledState::getStateName()
{
    return "ElectrodesNotInstalledState";
}
