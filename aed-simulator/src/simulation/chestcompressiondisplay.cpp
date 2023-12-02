#include "chestcompressiondisplay.h"

#include "../mainwindow.h"

ChestCompressionDisplay::ChestCompressionDisplay(MainWindow *mainWindow, QWidget *parent) : QLabel(parent)
{
    this->mainWindow = mainWindow;

    loadImages();
    patientTypeIndex = 0;
    compressionTypeIndex = 0;

    updateDisplay();

    setFixedSize(40, 150);
    setVisible(false);
}

void ChestCompressionDisplay::setPatientTypeIndex(int patientTypeIndex)
{
    this->patientTypeIndex = patientTypeIndex;
    updateDisplay();
}

void ChestCompressionDisplay::setCompressionTypeIndex(int compressionTypeIndex)
{
    this->compressionTypeIndex = compressionTypeIndex;
    updateDisplay();
}

void ChestCompressionDisplay::loadImages()
{
    const int size = PATIENT_TYPES.size() * COMPRESSION_TYPES.size();
    pixmaps.reserve(size);

    for (int i = 0; i < size; ++i)
    {
        const QString patientType = PATIENT_TYPES[i / COMPRESSION_TYPES.size()];
        const QString compressionType = COMPRESSION_TYPES[i % COMPRESSION_TYPES.size()];
        const QString imagePath = QString(":/images/chest-compression-meter/%1_meter_%2.png").arg(patientType).arg(compressionType);
        pixmaps.append(QPixmap(imagePath));
    }
}

void ChestCompressionDisplay::updateDisplay()
{
    QPixmap pixmap = pixmaps[patientTypeIndex * COMPRESSION_TYPES.size() + compressionTypeIndex];
    setPixmap(pixmap);
}
