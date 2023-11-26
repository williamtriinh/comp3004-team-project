#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "aedimage.h"
#include "states/basestate.h"
#include "qcustomplot.h"
#include "shockindicatorbutton.h"

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
    enum class UnitStatus {
        OK,
        FAILED,
        DEFAULT,
    };


    enum class ElectrodePadsAttachedState {
        NOT_ATTACHED,
        ATTACHED,
    };

    enum class PatientStatus{
        VHAB,
        VTACH,
        NORMAL,
        DEFAULT,
    };

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

    UnitStatus getUnitStatus();
    void setUnitStatus(UnitStatus status);

    int getBattery();
    void setBattery(int value);

    bool getElectrodesInstalled();


    ElectrodePadsAttachedState getElectrodePadsAttachedState();
    void setElectrodePadsAttached(ElectrodePadsAttachedState state);



    QCustomPlot *placeholderGraph;

    ShockIndicatorButton *shockIndicatorButton;

    PatientStatus getPatientStatus();
    void setPatientStatus(PatientStatus status);

    void displayVTACHECG();
    void displayVHABECG();
    void displayNormalECG();

    void shockIndicatorButtonFlashing();
    void shockIndicatorButtonStopFlashing();

public slots:
    void toggleElectrodesInstalled();

private:
    Ui::MainWindow *ui;
    BaseState *state;

    QPlainTextEdit *console;

    /**
     * Kepps track of which AED image has its light flashing
     */
    AEDImage *activeAEDImage;

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
     * Sets the appropriate AED image depending on the current state
     */
    void updateActiveAEDImage();


    /**
     * The patient's status
     */
    PatientStatus patientStatus;

signals:
    void stateChanged(BaseState *state);
    void unitStatusChanged(UnitStatus status);
    void batteryChanged(int battery);
    void electrodesInstalledChanged(bool electrodesInstalled);
    void electrodePadsAttachedStateChanged(ElectrodePadsAttachedState state);

    void patientStatusChanged(PatientStatus status);

};
#endif // MAINWINDOW_H
