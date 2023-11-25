#include "batterieswidget.h"

#include "../mainwindow.h"

#include <QLabel>
#include <QVBoxLayout>

BatteriesWidget::BatteriesWidget(MainWindow *mainWindow, QWidget *parent)
    : QWidget{parent}
{
    QLabel *label = new QLabel("Battery");

    spinBox = new QSpinBox();
    spinBox->setMinimum(0);
    spinBox->setMaximum(100);
    updateSpinBox(mainWindow->getBattery());

    button = new QPushButton("Update Battery");
    connect(button, &QPushButton::clicked, mainWindow, [=]() { mainWindow->setBattery(spinBox->value()); });

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);
    layout->addWidget(label);
    layout->addWidget(spinBox);
    layout->addWidget(button);

    connect(mainWindow, &MainWindow::batteryChanged, this, &BatteriesWidget::updateSpinBox);
}

void BatteriesWidget::updateSpinBox(int battery) {
    spinBox->setValue(battery);
}
