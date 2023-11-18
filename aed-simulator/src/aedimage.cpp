#include "aedimage.h"
#include "ui_aedimage.h"

#include <QDebug>
#include <QPixmap>
#include <QSizePolicy>

AEDImage::AEDImage(QString imagePath, int height, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AEDImage)
{
    ui->setupUi(this);

    QPixmap pixmap = QPixmap(imagePath).scaledToHeight(height);
    ui->label->setPixmap(pixmap);

    // Set the widget's size to the size of the pixmap
    setFixedSize(pixmap.size());
}

AEDImage::~AEDImage()
{
    delete ui;
}
