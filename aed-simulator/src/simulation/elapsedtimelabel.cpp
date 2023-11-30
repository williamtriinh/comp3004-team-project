#include "elapsedtimelabel.h"
#include <QVBoxLayout>
#include <QDebug>

ElapsedTimeLabel::ElapsedTimeLabel(QWidget *parent) : QWidget(parent)
{
    elapsedTimeLabel = new QLabel(this);
    elapsedTimeLabel->setFixedSize(200, 50); // Width: 200 pixels, Height: 50 pixels
    elapsedTimeLabel->setText("Elapsed Time: 00:00:00");

}

void ElapsedTimeLabel::startElapsedTime() {
    elapsedTimer.start();
    updateTimer = new QTimer(this);
    connect(updateTimer, &QTimer::timeout, this, &ElapsedTimeLabel::updateElapsedTimeDisplay);
    updateTimer->start(1000); // Update every second
}

qint64 ElapsedTimeLabel::getElapsedTime() const {
    return elapsedTimer.elapsed(); // Returns the time in milliseconds
}

void ElapsedTimeLabel::updateElapsedTimeDisplay() {
    qint64 elapsedTime = getElapsedTime();

    int hours = int(elapsedTime / (1000 * 60 * 60));
    int minutes = int((elapsedTime % (1000 * 60 * 60)) / (1000 * 60));
    int seconds = int((elapsedTime % (1000 * 60)) / 1000);

    QString timeString = QString("Elapsed Time: %1:%2:%3")
                             .arg(hours, 2, 10, QChar('0'))
                             .arg(minutes, 2, 10, QChar('0'))
                             .arg(seconds, 2, 10, QChar('0'));

    elapsedTimeLabel->setText(timeString);
}

void ElapsedTimeLabel::resetElapsedTime() {
    if (updateTimer->isActive()) {
        updateTimer->stop();
    }
    elapsedTimer.restart();
    updateElapsedTimeDisplay();
}
