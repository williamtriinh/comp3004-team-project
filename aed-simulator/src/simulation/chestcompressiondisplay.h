#ifndef CHESTCOMPRESSIONDISPLAY_H
#define CHESTCOMPRESSIONDISPLAY_H

#include <QLabel>
#include <QPixmap>
#include <QVector>

class MainWindow;

class ChestCompressionDisplay : public QLabel
{
public:
    const QStringList PATIENT_TYPES = { "adult", "child", "infant" };
    const QStringList COMPRESSION_TYPES = { "default", "shallow", "good", "deep" };

    ChestCompressionDisplay(MainWindow *mainWindow, QWidget *parent = nullptr);

    void setPatientTypeIndex(int patientTypeIndex);

    void setCompressionTypeIndex(int compressionTypeIndex);

private:
    MainWindow *mainWindow;

    QVector<QPixmap> pixmaps;

    /**
     * Index pointing to the current item in PATIENT_TYPES
     */
    int patientTypeIndex;

    /**
     * Index pointing to the current item in
     */
    int compressionTypeIndex;

    /**
     * Loads the images into the pixmaps array
     */
    void loadImages();

    /**
     * Updates the meter to the current patient and compression indices
     */
    void updateDisplay();
};

#endif // CHESTCOMPRESSIONDISPLAY_H
