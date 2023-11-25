#ifndef INSTALLELECTRODESWIDGET_H
#define INSTALLELECTRODESWIDGET_H

#include <QLabel>
#include <QPushButton>
#include <QWidget>

class MainWindow;

class InstallElectrodesWidget : public QWidget
{
    Q_OBJECT
public:
    explicit InstallElectrodesWidget(MainWindow *mainWindow, QWidget *parent = nullptr);

private:
    QLabel *label;
    QPushButton *button;

private slots:
    void updateLabel(bool electrodesInstalled);

signals:
    void buttonClicked();
};

#endif // INSTALLELECTRODESWIDGET_H
