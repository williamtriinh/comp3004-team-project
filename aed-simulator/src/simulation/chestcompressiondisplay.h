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

private:
    MainWindow *mainWindow;

    QVector<QPixmap> pixmaps;

    /**
     * The current patient type from PATIENT_TYPES
     */
    QString patientType;

    /**
     * The current compression type from COMPRESSION_TYPES
     */
    QString compressionType;

    /**
     * Loads the images into the pixmaps array
     */
    void loadImages();

private slots:
    void updatePatientTypeIndex();
};

#endif // CHESTCOMPRESSIONDISPLAY_H
