#include "attachelectrodepadswidget.h"

#include "../mainwindow.h"

#include <QLabel>
#include <QVBoxLayout>

AttachElectrodePadsWidget::AttachElectrodePadsWidget(MainWindow *mainWindow, QWidget *parent)
    : QWidget{parent}
{
    this->mainWindow = mainWindow;
    QLabel *label = new QLabel("Attach Electrode Pads");

    // TODO: Figure out what to do with patientComboBox
    patientComboBox = new QComboBox();
    patientComboBox->addItem("Adult");
    patientComboBox->addItem("Child or < 55 lbs");

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
