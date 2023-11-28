#ifndef BATTERIESWIDGET_H
#define BATTERIESWIDGET_H

#include <QPushButton>
#include <QSpinBox>
#include <QWidget>

class MainWindow;

class BatteriesWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BatteriesWidget(MainWindow *mainWindow, QWidget *parent = nullptr);

private:
    MainWindow *mainWindow;
    QSpinBox *spinBox;
    QPushButton *button;

private slots:
    void updateSpinBox(int battery);

signals:
    void buttonClicked();
};

#endif // BATTERIESWIDGET_H
