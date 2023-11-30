#include "aedimage.h"

#include "mainwindow.h"

#include <QSizePolicy>

AEDImage::AEDImage(MainWindow *mainWindow, QString imageName, int height, QString stateName, QWidget *parent)
    : QLabel(parent)
{
    this->mainWindow = mainWindow;
    connect(mainWindow, &MainWindow::stateChanged, this, &AEDImage::handleStateChanged);

    timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, &QTimer::timeout, this, &AEDImage::toggleIlluminated);

    illuminated = false;
    this->stateName = stateName;

    offPixmap = QPixmap(":/images/steps/" + imageName + "_off.png").scaledToHeight(height);
    onPixmap = QPixmap(":/images/steps/" + imageName + "_on.png").scaledToHeight(height);
    setPixmap(offPixmap);
    setFixedSize(offPixmap.size()); // Set the widget's size to the size of the pixmap
}

void AEDImage::turnOn()
{
    illuminated = true;
    setPixmap(onPixmap);
    timer->start(AEDImage::LIGHT_FLASH_INTERVAL);
}

void AEDImage::turnOff()
{
    illuminated = false;
    setPixmap(offPixmap);
    timer->stop();
}

void AEDImage::toggleIlluminated()
{
    illuminated = !illuminated;
    setPixmap(illuminated ? onPixmap : offPixmap);
    timer->start(AEDImage::LIGHT_FLASH_INTERVAL);
}

void AEDImage::handleStateChanged(BaseState *state)
{
    if (stateName == state->getStateName())
    {
        turnOn();
    } else {
        turnOff();
    }
}
