#include "chestcompressiondisplay.h"

#include "../mainwindow.h"

ChestCompressionDisplay::ChestCompressionDisplay(MainWindow *mainWindow, QWidget *parent) : QLabel(parent)
{
    this->mainWindow = mainWindow;
    connect(mainWindow, &MainWindow::patientTypeChanged, this, &ChestCompressionDisplay::updatePatientTypeIndex);

    loadImages();
    patientType = PATIENT_TYPES[0];
    compressionType = COMPRESSION_TYPES[0];

    setFixedSize(40, 150);
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

    setPixmap(pixmaps.first());
}

void ChestCompressionDisplay::updatePatientTypeIndex()
{
    switch (mainWindow->getPatientType())
    {
    case MainWindow::PatientType::ADULT:
        patientType = PATIENT_TYPES[0];
        break;
    case MainWindow::PatientType::CHILD:
        patientType = PATIENT_TYPES[1];
        break;
    case MainWindow::PatientType::INFANT:
        patientType = PATIENT_TYPES[2];
        break;
    }
}
