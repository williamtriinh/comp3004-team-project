#include "batterieswidget.h"

#include "../mainwindow.h"
#include "../states/poweredoffstate.h"

#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

BatteriesWidget::BatteriesWidget(MainWindow *mainWindow, QWidget *parent)
    : QWidget{parent}
{
    this->mainWindow = mainWindow;
    QLabel *label = new QLabel("Battery");

    spinBox = new QSpinBox();
    spinBox->setMinimum(0);
    spinBox->setMaximum(100);
    spinBox->setValue(100);

    QPushButton *button = new QPushButton("Update Battery");
    connect(button, &QPushButton::clicked, this, &BatteriesWidget::updateBattery);

    QHBoxLayout *horLayout = new QHBoxLayout;
    horLayout->setContentsMargins(0, 0, 0, 0);
    horLayout->addWidget(spinBox);
    horLayout->addWidget(button);

    button = new QPushButton("Recharge Battery");
    connect(button, &QPushButton::clicked, mainWindow, &MainWindow::rechargeBatteries);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);
    layout->addWidget(label);
    layout->addLayout(horLayout);
    layout->addWidget(button);
}

void BatteriesWidget::updateBattery() {
    int battery = spinBox->value();
    mainWindow->setBattery(battery);

    if (battery <= 0)
        mainWindow->changeState(new PoweredOffState(mainWindow));
}
