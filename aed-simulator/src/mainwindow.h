#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "states/basestate.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * The main application window for the AED simulator.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    static const int DISPLAY_SIZE = 700;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    /**
     * Changes the current state to the specified state
     * @param newState The new state
     */
    void changeState(BaseState *newState);

private:
    Ui::MainWindow *ui;
    BaseState *state;
};
#endif // MAINWINDOW_H
