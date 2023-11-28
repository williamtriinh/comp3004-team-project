#ifndef ENDPROGRAMWIDGET_H
#define ENDPROGRAMWIDGET_H

#include "../states/poweredoffstate.h"

#include <QComboBox>
#include <QWidget>

class MainWindow;

class EndProgramWidget : public QWidget
{
    Q_OBJECT
public:
    explicit EndProgramWidget(MainWindow *mainWindow, QWidget *parent = nullptr);

private:

    MainWindow *mainWindow;

    QComboBox *EndProgramComboBox;

private slots:
    void handleEndProgramComboBoxChanged(int index);

signals:
    void buttonClicked();
};

#endif
