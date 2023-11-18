#ifndef AEDIMAGE_H
#define AEDIMAGE_H

#include <QLabel>

/**
 * Widget for displaying images for the AED.
 */
class AEDImage : public QLabel
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
};

#endif // AEDIMAGE_H
