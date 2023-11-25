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
    connect(timer, &QTimer::timeout, this, &AEDImage::toggleLight);

    illuminated = false;
    this->stateName = stateName;

    offPixmap = QPixmap(":/images/steps/" + imageName + "_off.png").scaledToHeight(height);
    onPixmap = QPixmap(":/images/steps/" + imageName + "_on.png").scaledToHeight(height);
    setPixmap(offPixmap);
    setFixedSize(offPixmap.size()); // Set the widget's size to the size of the pixmap
}

void AEDImage::toggleLight()
{
    illuminated = !illuminated;
    setPixmap(illuminated ? onPixmap : offPixmap);
    timer->start(illuminated ? AEDImage::LIGHT_ON_DURATION_MS : AEDImage::LIGHT_OFF_DURATION_MS);
}

void AEDImage::handleStateChanged(BaseState *state)
{
    if (stateName == state->getStateName())
    {
        toggleLight();
    } else {
        timer->stop();
        illuminated = false;
        setPixmap(offPixmap);
    }
}
