#include "statusindicator.h"

#include <QPixmap>

StatusIndicator::StatusIndicator(QWidget *parent)
    : QLabel(parent)
{
    // The image sizes are all the same
    QPixmap statusIndicatorOffImage(":/images/status_indicator_off.png");
    QPixmap statusIndicatorFailedImage(":/images/status_indicator_failed.png");
    QPixmap statusIndicatorPassedImage(":/images/status_indicator_passed.png");

    setFixedSize(statusIndicatorOffImage.size());
    setPixmap(statusIndicatorOffImage);
}
