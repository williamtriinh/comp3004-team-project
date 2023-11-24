#include "batterieswidget.h"

#include "../mainwindow.h"

#include <QVBoxLayout>

BatteriesWidget::BatteriesWidget(MainWindow *mainWindow, QWidget *parent)
    : QWidget{parent}
{
    spinBox = new QSpinBox();
    spinBox->setMinimum(0);
    spinBox->setMaximum(100);
    updateSpinBox(mainWindow->getBattery());

    button = new QPushButton("Update Battery");
    connect(button, &QPushButton::clicked, mainWindow, [=]() { mainWindow->setBattery(spinBox->value()); });

    QVBoxLayout *layout = new QVBoxLayout;
    setLayout(layout);
    layout->addWidget(spinBox);
    layout->addWidget(button);

    connect(mainWindow, &MainWindow::batteryChanged, this, &BatteriesWidget::updateSpinBox);
}

void BatteriesWidget::updateSpinBox(int battery) {
    spinBox->setValue(battery);
}
