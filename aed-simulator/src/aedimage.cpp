#include "aedimage.h"

#include <QPixmap>
#include <QSizePolicy>

AEDImage::AEDImage(QString imagePath, int height, QWidget *parent)
    : QLabel(parent)
{
    QPixmap pixmap = QPixmap(imagePath).scaledToHeight(height);
    setPixmap(pixmap);

    // Set the widget's size to the size of the pixmap
    setFixedSize(pixmap.size());
}
