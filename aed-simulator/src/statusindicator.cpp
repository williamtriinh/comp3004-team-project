#include "statusindicator.h"
#include "ui_statusindicator.h"

#include <QPixmap>

StatusIndicator::StatusIndicator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatusIndicator)
{
    ui->setupUi(this);

    // The image sizes are all the same
    QPixmap statusIndicatorOffImage = QPixmap(":/images/status_indicator_off.png");
    QPixmap statusIndicatorFailedImage = QPixmap(":/images/status_indicator_failed.png");
    QPixmap statusIndicatorPassedImage = QPixmap(":/images/status_indicator_passed.png");

    ui->label->setFixedSize(statusIndicatorOffImage.size());
    ui->label->setPixmap(statusIndicatorOffImage);
}

StatusIndicator::~StatusIndicator()
{
    delete ui;
}
