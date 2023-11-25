#include "installelectrodeswidget.h"

#include "../mainwindow.h"

#include <QVBoxLayout>

InstallElectrodesWidget::InstallElectrodesWidget(MainWindow *mainWindow, QWidget *parent)
    : QWidget{parent}
{
    label = new QLabel();
    updateLabel(mainWindow->getElectrodesInstalled());

    button = new QPushButton("Install/Uninstall");
    connect(button, &QPushButton::clicked, mainWindow, &MainWindow::toggleElectrodesInstalled);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);
    layout->addWidget(label);
    layout->addWidget(button);

    connect(mainWindow, &MainWindow::electrodesInstalledChanged, this, &InstallElectrodesWidget::updateLabel);
}

void InstallElectrodesWidget::updateLabel(bool electrodesInstalled) {
    QString text = "Electrodes Installed: true";
    if (!electrodesInstalled) text = "Electrodes Installed: false";
    label->setText(text);
}
