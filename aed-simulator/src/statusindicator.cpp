#include "statusindicator.h"

#include "mainwindow.h"

StatusIndicator::StatusIndicator(MainWindow *mainWindow, QWidget *parent)
    : QLabel(parent)
{
    this->mainWindow = mainWindow;

    // The image sizes are all the same
    offPixmap = QPixmap(":/images/status_indicator_off.png");
    failedPixmap = QPixmap(":/images/status_indicator_failed.png");
    passedPixmap = QPixmap(":/images/status_indicator_passed.png");

    setFixedSize(offPixmap.size());
    setPixmap(offPixmap);

    connect(mainWindow, &MainWindow::unitStatusChanged, this, &StatusIndicator::updateIndicator);
    connect(mainWindow, &MainWindow::batteryChanged, this, &StatusIndicator::updateIndicator);
}

void StatusIndicator::updateIndicator()
{
    if (mainWindow->getBattery() <= 0)
    {
        // When the batteries are dead display X indicator
        setPixmap(failedPixmap);
        return;
    }

    switch(mainWindow->getUnitStatus())
    {
    case MainWindow::UnitStatus::FAILED:
        setPixmap(failedPixmap);
        break;
    case MainWindow::UnitStatus::OK:
        setPixmap(passedPixmap);
        break;
    default:
        setPixmap(offPixmap);
    }
}
