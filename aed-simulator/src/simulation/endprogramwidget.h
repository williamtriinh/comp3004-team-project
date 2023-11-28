#ifndef ENDPROGRAMWIDGET_H
#define ENDPROGRAMWIDGET_H

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

private slots:
    void handleEndProgramComboBoxChanged(int index);
};

#endif
