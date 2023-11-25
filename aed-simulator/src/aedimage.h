#ifndef AEDIMAGE_H
#define AEDIMAGE_H

#include "states/basestate.h"

#include <QLabel>
#include <QPixmap>
#include <QTimer>

class MainWindow;

/**
 * Widget for displaying images for the AED.
 */
class AEDImage : public QLabel
{
    Q_OBJECT

public:
    static const int LIGHT_OFF_DURATION_MS = 1000;
    static const int LIGHT_ON_DURATION_MS = 500;

    /**
     * Constructs a widget with the specified image resource and height
     * @param mainWindow the main window where the state resides
     * @param imageName the name of the image
     * @param height displayed height of the image
     * @param stateName the name of the state the image corresponds to
     * @param parent
     */
    explicit AEDImage(
        MainWindow *mainWidow,
        QString imageName,
        int height,
        QString stateName,
        QWidget *parent
    );

private:
    MainWindow *mainWindow;

    /**
     * Responsible for controlling the flashing light
     */
    QTimer *timer;

    /**
     * Keeps track of whether the light should be on (true) or off (false).
     */
    bool illuminated;

    /**
     * The name of the state the image corresponds to
     */
    QString stateName;

    /**
     * The pixmap of the off version of the graphic
     */
    QPixmap offPixmap;

    /**
     * The pixmap of the illuminated version of the graphic
     */
    QPixmap onPixmap;

private slots:
    /**
     * Turns on/off the light and sets the appropriate pixmap
     */
    void toggleLight();

    /**
     * Handles mainWindow state change
     */
    void handleStateChanged(BaseState *state);
};

#endif // AEDIMAGE_H
