#include "endprogramwidget.h"

#include "../mainwindow.h"
#include "../states/poweredoffstate.h"

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
    connect(endProgramComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &EndProgramWidget::handleEndProgramComboBoxChanged);

    QVBoxLayout *layout = new QVBoxLayout();
    setLayout(layout);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(label);
    layout->addWidget(endProgramComboBox);
}

void EndProgramWidget::handleEndProgramComboBoxChanged(int index)
{
    switch (index)
    {
    case 1:
        mainWindow->changeState(new PoweredOffState(mainWindow));
        break;
    case 2:
        if (mainWindow->isCurrentStatePerformCPR()) {
            mainWindow->changeState(new PoweredOffState(mainWindow));
        }
        break;
    case 3:
        if (mainWindow->isCurrentStatePerformCPR()) {
            mainWindow->changeState(new PoweredOffState(mainWindow));
        }
        break;
    }
}
