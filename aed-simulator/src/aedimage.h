#ifndef AEDIMAGE_H
#define AEDIMAGE_H

#include <QWidget>

namespace Ui {
class AEDImage;
}

/**
 * Widget for displaying the graphical steps.
 */
class AEDImage : public QWidget
{
    Q_OBJECT

public:
    /**
     * Constructs a widget with the specified image resource and height
     * @param imagePath path to image
     * @param height displayed height of the image
     *
     */
    explicit AEDImage(QString imagePath, int height, QWidget *parent);
    ~AEDImage();

private:
    Ui::AEDImage *ui;
};

#endif // AEDIMAGE_H
