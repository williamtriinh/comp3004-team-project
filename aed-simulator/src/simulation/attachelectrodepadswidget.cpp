#include "attachelectrodepadswidget.h"

#include "../mainwindow.h"

#include <QLabel>
#include <QVBoxLayout>

AttachElectrodePadsWidget::AttachElectrodePadsWidget(MainWindow *mainWindow, QWidget *parent)
    : QWidget{parent}
{
    this->mainWindow = mainWindow;
    QLabel *label = new QLabel("Attach Electrode Pads");

    patientComboBox = new QComboBox();
    patientComboBox->addItem("Adult");
    patientComboBox->addItem("Child");
    patientComboBox->addItem("Infant");
    connect(patientComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &AttachElectrodePadsWidget::handlePatientComboBoxChanged);

    attachmentComboBox = new QComboBox();
    attachmentComboBox->addItem("Not attached");
    attachmentComboBox->addItem("Attached");
    connect(attachmentComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &AttachElectrodePadsWidget::handleAttachmentComboBoxChanged);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);
    layout->addWidget(label);
    layout->addWidget(patientComboBox);
    layout->addWidget(attachmentComboBox);
}

void AttachElectrodePadsWidget::handlePatientComboBoxChanged(int index)
{
    mainWindow->getChestCompressionDisplay()->setPatientTypeIndex(index);
}

void AttachElectrodePadsWidget::handleAttachmentComboBoxChanged(int index)
{
    MainWindow::ElectrodePadsAttachedState state;
    switch (index)
    {
    case 1:
        state = MainWindow::ElectrodePadsAttachedState::ATTACHED;
        break;
    default:
        state = MainWindow::ElectrodePadsAttachedState::NOT_ATTACHED;
    }
    mainWindow->setElectrodePadsAttached(state);
}
