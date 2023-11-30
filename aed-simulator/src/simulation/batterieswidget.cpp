#include "batterieswidget.h"

#include "../mainwindow.h"

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
    updateSpinBox(mainWindow->getBattery());

    QPushButton *button = new QPushButton("Update Battery");
    connect(button, &QPushButton::clicked, mainWindow, [=](){ mainWindow->setBattery(spinBox->value()); });

    QHBoxLayout *horLayout = new QHBoxLayout;
    horLayout->setContentsMargins(0, 0, 0, 0);
    horLayout->addWidget(spinBox);
    horLayout->addWidget(button);

    button = new QPushButton("Recharge Battery");
    connect(button, &QPushButton::clicked, mainWindow, [=]() { mainWindow->setBattery(100); });

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);
    layout->addWidget(label);
    layout->addLayout(horLayout);
    layout->addWidget(button);
}

void BatteriesWidget::updateSpinBox(int battery) {
    spinBox->setValue(battery);
}
