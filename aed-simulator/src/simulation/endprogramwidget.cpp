#include "endprogramwidget.h"


#include "../mainwindow.h"

#include <QLabel>
#include <QVBoxLayout>

EndProgramWidget::EndProgramWidget(MainWindow *mainWindow, QWidget *parent)
    : QWidget{parent}
{
    this->mainWindow = mainWindow;

    QLabel *label = new QLabel("End Program");


    QComboBox *EndProgramComboBox = new QComboBox;
    EndProgramComboBox->addItem("Select End Program");
    EndProgramComboBox->addItem("Emergency Services' arrives");
    EndProgramComboBox->addItem("CPR regenerates the heart beat");
    EndProgramComboBox->addItem("The shock revives the patient");
    connect(EndProgramComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &EndProgramWidget::handleEndProgramComboBoxChanged);
    QVBoxLayout *layout = new QVBoxLayout();
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);
    layout->addWidget(label);
    layout->addWidget(EndProgramComboBox);
}

void EndProgramWidget::handleEndProgramComboBoxChanged(int index){
    switch (index)
    {
    case 1:
        mainWindow->changeState(new PoweredOffState(mainWindow));
        break;

    case 2:
        mainWindow->changeState(new PoweredOffState(mainWindow));
        break;

    case 3:
        mainWindow->changeState(new PoweredOffState(mainWindow));
        break;

    }
}
