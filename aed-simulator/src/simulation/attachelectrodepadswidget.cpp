#include "attachelectrodepadswidget.h"

#include "../mainwindow.h"

#include <QLabel>
#include <QVBoxLayout>

AttachElectrodePadsWidget::AttachElectrodePadsWidget(MainWindow *mainWindow, QWidget *parent)
    : QWidget{parent}
{
    QLabel *label = new QLabel("Attach Electrode Pads");

    patientComboBox = new QComboBox();
    patientComboBox->addItem("Adult");
    patientComboBox->addItem("Child or < 55 lbs");

    attachmentComboBox = new QComboBox();
    attachmentComboBox->addItem("Not attached");
    attachmentComboBox->addItem("Attached successfully");
    attachmentComboBox->addItem("Attached failed");

    button = new QPushButton("Update");

    QVBoxLayout *layout = new QVBoxLayout();
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);
    layout->addWidget(label);
    layout->addWidget(patientComboBox);
    layout->addWidget(attachmentComboBox);
    layout->addWidget(button);
}
