#include "endprogramwidget.h"

#include "../mainwindow.h"
#include "../states/poweredoffstate.h"
#include "../states/analyzingstate.h"

#include <QLabel>
#include <QVBoxLayout>

EndProgramWidget::EndProgramWidget(MainWindow *mainWindow, QWidget *parent)
    : QWidget{parent}
{
    this->mainWindow = mainWindow;

    QLabel *label = new QLabel("End Program");

    QComboBox *endProgramComboBox = new QComboBox;
    endProgramComboBox->addItem("Select End Program");
    endProgramComboBox->addItem("Emergency Services' arrives");
    endProgramComboBox->addItem("CPR regenerates the heart beat");
    endProgramComboBox->addItem("The shock revives the patient");
    endProgramComboBox->addItem("Patient Dies");
    connect(endProgramComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &EndProgramWidget::handleEndProgramComboBoxChanged);

    QVBoxLayout *layout = new QVBoxLayout();
    setLayout(layout);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(label);
    layout->addWidget(endProgramComboBox);
}

void EndProgramWidget::handleEndProgramComboBoxChanged(int index)
{
    MainWindow::EndOfProgramStatus state;
    switch (index)
    {
    case 1:
        state = MainWindow::EndOfProgramStatus::EMSARRIVES;
        mainWindow->playMessage("EMS has arrived. AED powering off");
        mainWindow->changeState(new PoweredOffState(mainWindow));
        break;
    case 2:
        state = MainWindow::EndOfProgramStatus::CPRREVIVESPATIENT;
        break;
    case 3:
        state = MainWindow::EndOfProgramStatus::SHOCKREVIVESPATIENT;
        break;

    case 4:
        state = MainWindow::EndOfProgramStatus::PATIENTDIES;
        mainWindow->playMessage("Patient has died");
        if (mainWindow->isCurrentStatePerformCPR() || mainWindow->isCurrentStateAnalyzingState()){
            mainWindow->displayAsystoleECG();
        }
        break;

    default:
        state = MainWindow::EndOfProgramStatus::DEFAULT;

    }
    mainWindow->setEndOfProgramStatus(state);
}
