#include "statusindicator.h"

StatusIndicator::StatusIndicator(QWidget *parent)
    : QLabel(parent)
{
    // The image sizes are all the same
    offPixmap = QPixmap(":/images/status_indicator_off.png");
    failedPixmap = QPixmap(":/images/status_indicator_failed.png");
    passedPixmap = QPixmap(":/images/status_indicator_passed.png");

    setFixedSize(offPixmap.size());
    setPixmap(offPixmap);
}
