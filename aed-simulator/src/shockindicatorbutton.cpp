#include "shockindicatorbutton.h"

ShockIndicatorButton::ShockIndicatorButton(QWidget *parent)
    : QPushButton(parent)
{
    offPixmap = QPixmap(":/images/shock_indicator_off.png");
    onPixmap = QPixmap(":/images/shock_indicator_on.png");

    setStyleSheet("QPushButton { background-color: transparent; }");
    setIcon(QIcon(offPixmap));
    setIconSize(offPixmap.size());
}
