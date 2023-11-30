#include "patientstatuswidget.h"


#include "../mainwindow.h"

#include <QLabel>
#include <QVBoxLayout>

PatientStatusWidget::PatientStatusWidget(MainWindow *mainWindow, QWidget *parent)
    : QWidget{parent}
{
    this->mainWindow = mainWindow;

    QLabel *label = new QLabel("Patient's Condition");

    // Determine's patient's status
    QComboBox *patientStatusComboBox = new QComboBox;
    patientStatusComboBox->addItem("Select Patient Status");
    patientStatusComboBox->addItem("Pulseless Ventricular Tachycardia (Shock Given)");
    patientStatusComboBox->addItem("Ventricular Fibrillation (Shock Given)");
    patientStatusComboBox->addItem("Asystole (Shock Not Given)");
    patientStatusComboBox->addItem("Pulseless Electrical Activity (Shock Not Given)");
    connect(patientStatusComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &PatientStatusWidget::handlePatientStatusComboBoxChanged);
    QVBoxLayout *layout = new QVBoxLayout();
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);
    layout->addWidget(label);
    layout->addWidget(patientStatusComboBox);
}

void PatientStatusWidget::handlePatientStatusComboBoxChanged(int index){
    MainWindow::PatientStatus state;
        switch (index)
        {
        case 1:
            state = MainWindow::PatientStatus::VT;
            break;

        case 2:
            state = MainWindow::PatientStatus::VF;
            break;

        case 3:
            state = MainWindow::PatientStatus::ASYSTOLE;
            break;

        case 4:
            state = MainWindow::PatientStatus::PEA;
            break;

        default:
            state = MainWindow::PatientStatus::DEFAULT;
        }
        mainWindow->setPatientStatus(state);
}
