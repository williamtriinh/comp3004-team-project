#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "states/basestate.h"

#include <QMainWindow>
#include <QPlainTextEdit>

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

    /**
     * Prints a message to the console
     * @param message The message to display
     */
    void playMessage(QString message);

    int getBattery();
    void setBattery(int value);

    bool getElectrodesInstalled();

public slots:
    void toggleElectrodesInstalled();

private:
    Ui::MainWindow *ui;
    BaseState *state;

    QPlainTextEdit *console;

    /**
     * The AED's battery percentage from 0 (empty) to 100 (full)
     */
    int battery;

    bool electrodesInstalled;

signals:
    void batteryChanged(int battery);
    void electrodesInstalledChanged(bool electrodesInstalled);
};
#endif // MAINWINDOW_H
