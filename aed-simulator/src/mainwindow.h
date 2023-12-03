#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "aedimage.h"
#include "states/basestate.h"
#include "qcustomplot.h"
#include "shockindicatorbutton.h"
#include <QMainWindow>
#include <QPlainTextEdit>
#include "simulation/elapsedtimelabel.h"

#include "graphs.h"

#include "simulation/chestcompressiondisplay.h"


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
    enum class UnitStatus {
        OK,
        FAILED,
        DEFAULT,
    };


    enum class ElectrodePadsAttachedState{
        NOT_ATTACHED,
        ATTACHED,
    };

    enum class PatientStatus {
        VT,
        VF,
        PEA,
        ASYSTOLE,
        DEFAULT,
    };



    static const int DISPLAY_SIZE = 700;

    /**
     * How much the battery will deplete by when a shock occurs
     */
    static const int SHOCK_BATTERY_COST = 10;

    /**
     * The minimum battery level for the AED to pass the self-test
     */
    static const int MINIMUM_BATTERY = 40;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    /**
     * Changes the current state to the specified state
     * @param newState The new state
     */
    void changeState(BaseState *newState);

    BaseState *getState();

    /**
     * Prints a message to the console
     * @param message The message to display
     */
    void playMessage(QString message);

    UnitStatus getUnitStatus();
    void setUnitStatus(UnitStatus status);

    int getBattery();
    void setBattery(int value);

    /**
     * Checks whether the battery is >= MINIMUM_BATTERY
     * @return true if there's sufficient batter, otherwise, false
     */
    bool hasSufficientBattery();

    bool getElectrodesInstalled();

    ElectrodePadsAttachedState getElectrodePadsAttachedState();
    void setElectrodePadsAttached(ElectrodePadsAttachedState state);

    ChestCompressionDisplay *getChestCompressionDisplay();

    void updateShockCount();

    QCustomPlot *ecgGraph;

    ShockIndicatorButton *shockIndicatorButton;

    PatientStatus getPatientStatus();
    void setPatientStatus(PatientStatus status);

    void displayVTECG();
    void displayVFECG();
    void displayPEAECG();
    void displayAsystoleECG();
    void resetECGDisplay();

    void shockIndicatorButtonFlashing();
    void shockIndicatorButtonStopFlashing();

    bool getShockIndicatorButtonPressed();

    void deactivateShockIndicatorButtonPressed();

    // When user presses power button to turn on AED it begins the timer
    void startTimer();

    // When user presses power button to power off the AED it stops the timer
    void stopTimer();

    bool isCurrentStatePerformCPR() const;

public slots:
    void toggleElectrodesInstalled();


private:
    Ui::MainWindow *ui;
    BaseState *state;

    QPlainTextEdit *console;

    /**
     * The AED's self-test status
     */
    UnitStatus unitStatus;

    /**
     * The AED's battery percentage from 0 (empty) to 100 (full)
     */
    int battery;

    /**
     * Keeps track of whether the electrodes are installed (true) or not (false)
     */
    bool electrodesInstalled;

    /**
     * Keeps track of whether the electrode pads are attached to the patient
     */
    ElectrodePadsAttachedState electrodePadsAttachedState;

    /**
     * The patient's status
     */
    PatientStatus patientStatus;

    /**
     * Keeps track if the shock button has been pressed
     */
    bool shockIndicatorButtonPressed;

    /**
     * Label which shows battery
     */
    QLabel *batteryLabel;

    /**
     * Label which shows number of shocks left
     */
    QLabel *shockCountLabel;

    /**
     * Keeps track of number of shocks left
     */
    int numberOfShocks;

    ElapsedTimeLabel *elapsedTimeLabel;

    QWidget *displayWidget;

    /**
     * ECG Graph
     */
    Graphs *graph;

    ChestCompressionDisplay *chestCompressionDisplay;


signals:
    void stateChanged(BaseState *state);
    void unitStatusChanged(UnitStatus status);
    void batteryChanged(int battery);
    void electrodesInstalledChanged(bool electrodesInstalled);
    void electrodePadsAttachedStateChanged(ElectrodePadsAttachedState state);
    void patientStatusChanged(PatientStatus status);

private slots:
    void activateShockIndicatorButtonPressed();


};
#endif // MAINWINDOW_H
