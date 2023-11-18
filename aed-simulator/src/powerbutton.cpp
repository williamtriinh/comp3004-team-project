#include "powerbutton.h"

#include <QIcon>
#include <QPixmap>

PowerButton::PowerButton()
{
    QPixmap pixmap(":/images/power_button.png");
    setIcon(QIcon(pixmap));
    setIconSize(pixmap.size()); // Adjusts the button's size to match the pixmap too.
    setStyleSheet("QPushButton { border-radius: 10000px; }");
}
