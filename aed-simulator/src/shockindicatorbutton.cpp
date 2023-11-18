#include "shockindicatorbutton.h"

ShockIndicatorButton::ShockIndicatorButton(QWidget *parent)
    : QPushButton(parent)
{
    offPixmap = QPixmap(":/images/shock_indicator_off.png");
    onPixmap = QPixmap(":/images/shock_indicator_on.png");

    setStyleSheet("QPushButton { border-radius: 10000px; }");
    setIcon(QIcon(offPixmap));
    setIconSize(offPixmap.size());
}
