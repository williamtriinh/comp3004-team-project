#include "shockindicatorbutton.h"
#include <QTimer>

constexpr int LIGHT_ON_DURATION_MS = 500;
constexpr int LIGHT_OFF_DURATION_MS = 500;

ShockIndicatorButton::ShockIndicatorButton(QWidget *parent)
    : QPushButton(parent), illuminated(false)
{
    offPixmap = QPixmap(":/images/shock_indicator_off.png");
    onPixmap = QPixmap(":/images/shock_indicator_on.png");

    setStyleSheet("QPushButton { border-radius: 10000px; }");
    setIcon(QIcon(offPixmap));
    setIconSize(offPixmap.size());

    timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, &QTimer::timeout, this, &ShockIndicatorButton::toggleLight);
}

void ShockIndicatorButton::toggleLight()
{
    illuminated = !illuminated;
    setIcon(QIcon(illuminated ? onPixmap : offPixmap));
    timer->start(illuminated ? LIGHT_ON_DURATION_MS : LIGHT_OFF_DURATION_MS);
}

void ShockIndicatorButton::startFlashing() {
    toggleLight();
}

void ShockIndicatorButton::stopFlashing() {
    timer->stop();
    setIcon(QIcon(offPixmap));
    illuminated = false;
}
