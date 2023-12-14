#ifndef ENDPROGRAMWIDGET_H
#define ENDPROGRAMWIDGET_H

#include <QComboBox>
#include <QWidget>

#include "../states/basestate.h"

class MainWindow;

class EndProgramWidget : public QWidget
{
    Q_OBJECT
public:
    explicit EndProgramWidget(MainWindow *mainWindow, QWidget *parent = nullptr);

    // Resets the user's selection
    void reset();

private:
    MainWindow *mainWindow;
    QComboBox *endProgramComboBox;

private slots:
    void handleStateChanged(BaseState *state);
    void handleEndProgramComboBoxChanged(int index);
};

#endif
