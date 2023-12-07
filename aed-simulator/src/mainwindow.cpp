#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "aedimage.h"
#include "powerbutton.h"
#include "shockindicatorbutton.h"
#include "statusindicator.h"

#include "simulation/attachelectrodepadswidget.h"
#include "simulation/batterieswidget.h"
#include "simulation/chestcompressiondisplay.h"
#include "simulation/installelectrodeswidget.h"
#include "simulation/patientstatuswidget.h"
#include "simulation/endprogramwidget.h"

#include "states/analyzingstate.h"
#include "states/attachdefibrillatorpadsstate.h"
#include "states/callforhelpstate.h"
#include "states/checkresponsivenessstate.h"
#include "states/electrodesnotinstalledstate.h"
#include "states/performcprstate.h"
#include "states/poweredoffstate.h"
#include "states/selfteststate.h"

#include <QComboBox>
#include <QDebug>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QPlainTextEdit>
#include <QTime>
#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    unitStatus = UnitStatus::DEFAULT;
    battery = 100;
    electrodesInstalled = true;
    electrodePadsAttachedState = ElectrodePadsAttachedState::NOT_ATTACHED;
    patientStatus = PatientStatus::DEFAULT;
    endOfProgramStatus = EndOfProgramStatus::DEFAULT;
    numberOfShocks = 0;
    shockIndicatorButtonPressed = false;

    // Important to initialize state after other attributes
    state = new PoweredOffState(this);
    state->execute();

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->setContentsMargins(0, 0, 0, 0);
    QWidget *leftWidget = new QWidget;
    leftWidget->setLayout(leftLayout);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->setContentsMargins(0, 0, 0, 0);
    QWidget *mainWidget = new QWidget;
    mainWidget->setLayout(mainLayout);

    displayWidget = new QWidget;
    displayWidget->setFixedSize(DISPLAY_SIZE, DISPLAY_SIZE);

    QHBoxLayout *bottomLayout = new QHBoxLayout;
    mainLayout->setContentsMargins(0, 0, 0, 0);
    bottomLayout->addStretch();
    QWidget *bottomWidget = new QWidget;
    bottomWidget->setLayout(bottomLayout);
    bottomWidget->setFixedWidth(DISPLAY_SIZE);

    setCentralWidget(mainWidget);
    leftLayout->addWidget(displayWidget);
    leftLayout->addWidget(bottomWidget);
    mainLayout->addWidget(leftWidget);

    QPixmap greenRingPixmap = QPixmap(":/images/green_ring.png").scaledToHeight(DISPLAY_SIZE - 94);
    QLabel *greenRing = new QLabel(displayWidget);
    greenRing->setPixmap(greenRingPixmap);
    greenRing->setFixedSize(greenRingPixmap.size());
    greenRing->move(DISPLAY_SIZE / 2 - greenRing->width() / 2, DISPLAY_SIZE / 2 - greenRing->height() / 2);

    AEDImage *image1 = new AEDImage(this, "01_check_responsiveness", 120, "CheckResponsivenessState", displayWidget);
    image1->move(10, 210);

    AEDImage *image2 = new AEDImage(this, "02_call_emergency", 120, "CallForHelpState", displayWidget);
    image2->move(DISPLAY_SIZE / 2 - image2->width() / 2, 20);

    AEDImage *image3 = new AEDImage(this, "03_attach_pads", 120, "AttachDefibrillatorPadsState", displayWidget);
    image3->move(540, 270);

    AEDImage *image4 = new AEDImage(this, "04_dont_touch_patient", 120, "AnalyzingState", displayWidget);
    image4->move(385, 540);

    AEDImage *image5 = new AEDImage(this, "05_start_cpr", 200, "PerformCPRState", displayWidget);
    image5->move(50, 460);

    batteryLabel = new QLabel(displayWidget);
    batteryLabel->setText(QString("Battery Level: %1%").arg(battery));
    batteryLabel->move(DISPLAY_SIZE / 2 - 150, 200);
    connect(this, &MainWindow::batteryChanged, this, [=](){
        batteryLabel->setText(QString("Battery Level: %1%").arg(battery));
    });

    shockCountLabel = new QLabel(displayWidget);
    shockCountLabel->setText(QString("Shocks: %1").arg(numberOfShocks));
    shockCountLabel->move(DISPLAY_SIZE / 2 - 150, 220);

    elapsedTimeLabel = new ElapsedTimeLabel(displayWidget);
    elapsedTimeLabel->move(DISPLAY_SIZE / 2, 200);  // Adjust this position as needed
      
    chestCompressionDisplay = new ChestCompressionDisplay(this, displayWidget);
    chestCompressionDisplay->move(DISPLAY_SIZE / 2 + 110, 240);
      
    ecgGraph = new QCustomPlot(displayWidget);
    graph = new Graphs(ecgGraph);
    graph->setupGraph();
    ecgGraph->setFixedSize(300 - 48, 150); // Subtract width by 40px (chest compression meter) + 8px (spacing)
    ecgGraph->move(DISPLAY_SIZE / 2 - 150, 240);
    ecgGraph->setStyleSheet("QWidget { background-color: black; }");

    shockIndicatorButton = new ShockIndicatorButton(displayWidget);
    shockIndicatorButton->move(DISPLAY_SIZE / 2 - shockIndicatorButton->width() / 2, 440);
    connect(shockIndicatorButton,SIGNAL(released()),this,SLOT(activateShockIndicatorButtonPressed()));

    StatusIndicator *statusIndicator = new StatusIndicator(this);
    bottomLayout->insertWidget(0, statusIndicator);

    PowerButton *powerButton = new PowerButton();
    bottomLayout->insertWidget(2, powerButton);
    connect(powerButton, &QPushButton::clicked, this, [=]() { state->togglePower(); });

    // Widgets for simulating events/actions
    QVBoxLayout *rightLayout = new QVBoxLayout;
    QWidget *rightWidget = new QWidget();
    rightWidget->setLayout(rightLayout);
    rightWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    rightLayout->addWidget(new PatientStatusWidget(this));
    rightLayout->addWidget(new BatteriesWidget(this));
    rightLayout->addWidget(new InstallElectrodesWidget(this));
    rightLayout->addWidget(new AttachElectrodePadsWidget(this));
    rightLayout->addWidget(new EndProgramWidget(this));

    console = new QPlainTextEdit;
    console->setReadOnly(true);
    rightLayout->addWidget(console);

    mainLayout->addWidget(rightWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete state;
}

void MainWindow::changeState(BaseState *newState)
{
    // Don't change state if the new state is the same as the current state.
    if (newState->getStateName() == state->getStateName())
        return;

    qDebug() << "MainWindow changeState() called with" << newState->getStateName();
    if (state != nullptr) {
        delete state;
    }
    state = newState;
    state->initialize();
    emit stateChanged(state);
}

BaseState *MainWindow::getState()
{
    return state;
}

void MainWindow::playMessage(QString message)
{
    QString timeString = QTime::currentTime().toString("hh:mm:ss");
    console->appendPlainText(QString("[%1]: %2").arg(timeString).arg(message));
}

MainWindow::UnitStatus MainWindow::getUnitStatus()
{
    return unitStatus;
}

void MainWindow::setUnitStatus(UnitStatus status)
{
    unitStatus = status;
    emit unitStatusChanged(unitStatus);
}

int MainWindow::getBattery()
{
    return battery;
}

void MainWindow::setBattery(int value)
{
    battery = std::max(std::min(value, 100), 0);
    emit batteryChanged(battery);
}

bool MainWindow::hasSufficientBattery()
{
    return battery >= MINIMUM_BATTERY;
}

void MainWindow::toggleElectrodesInstalled()
{
    electrodesInstalled = !electrodesInstalled;

    if (electrodesInstalled)
    {
        restoreState();
    } else {
        // Don't save the state if it's the powered off state
        if (state->getStateName() != "PoweredOffState")
        {
            if (state != nullptr)
                lastState = state->getStateName();
            changeState(new ElectrodesNotInstalledState(this));
        }
    }

    emit electrodesInstalledChanged(electrodesInstalled);
}

void MainWindow::rechargeBatteries()
{
    setBattery(100);
    changeState(new PoweredOffState(this));
}

bool MainWindow::getElectrodesInstalled()
{
    return electrodesInstalled;
}

MainWindow::ElectrodePadsAttachedState MainWindow::getElectrodePadsAttachedState()
{
    return electrodePadsAttachedState;
}

void MainWindow::setElectrodePadsAttached(ElectrodePadsAttachedState state)
{
    electrodePadsAttachedState = state;
    emit electrodePadsAttachedStateChanged(electrodePadsAttachedState);
}

ChestCompressionDisplay *MainWindow::getChestCompressionDisplay()
{
    return chestCompressionDisplay;
}

MainWindow::PatientStatus MainWindow::getPatientStatus()
{
    return patientStatus;
}

void MainWindow::setPatientStatus(PatientStatus status)
{
    patientStatus = status;
}

MainWindow::EndOfProgramStatus MainWindow::getEndOfProgramStatus(){
    return endOfProgramStatus;
}
void MainWindow::setEndOfProgramStatus(EndOfProgramStatus status){
    endOfProgramStatus = status;
}


void MainWindow::displayVTECG(){
    graph->setDataVTECG();
}
void MainWindow::displayVFECG(){
    graph->setDataVFECG();
}

void MainWindow::displayAsystoleECG(){
    graph->setDataAsystoleECG();
}

void MainWindow::displayPEAECG(){
    graph->setDataPEAECG();
}

void MainWindow::resetECGDisplay(){
    graph->resetGraphData();
}

void MainWindow::shockIndicatorButtonFlashing() {
    shockIndicatorButton->startFlashing();
}

void MainWindow::shockIndicatorButtonStopFlashing(){
    shockIndicatorButton->stopFlashing();
}

void MainWindow::activateShockIndicatorButtonPressed(){
    shockIndicatorButtonPressed = true;
}

bool MainWindow::getShockIndicatorButtonPressed(){
    return shockIndicatorButtonPressed;
}

void MainWindow::deactivateShockIndicatorButtonPressed(){
    shockIndicatorButtonPressed = false;
}

void MainWindow::updateShockCount(){
    if(state->getStateName() == "PoweredOffState"){
        numberOfShocks = 0;
    }
    else{
        numberOfShocks++;
    }
    shockCountLabel->setText(QString("Shocks: %1").arg(numberOfShocks));
}

bool MainWindow::isCurrentStatePerformCPR() const {
    return dynamic_cast<PerformCPRState*>(state) != nullptr;
}


bool MainWindow::isCurrentStateAnalyzingState() const {
    return dynamic_cast<AnalyzingState*>(state) != nullptr;
}

void MainWindow::startTimer(){
    elapsedTimeLabel->startElapsedTime();

}

void MainWindow::stopTimer(){
    elapsedTimeLabel->resetElapsedTime();
}

void MainWindow::restoreState()
{
    if (lastState == "SelfTestState")
    {
        changeState(new SelfTestState(this));
    }
    else if (lastState == "CheckResponsivenessState")
    {
        changeState(new CheckResponsivenessState(this));
    }
    else if (lastState == "CallForHelpState")
    {
        changeState(new CallForHelpState(this));
    }
    else if (lastState == "AttachDefibrillatorPadsState")
    {
        changeState(new AttachDefibrillatorPadsState(this));
    }
    else if (lastState == "AnalyzingState")
    {
        changeState(new AnalyzingState(this));
    }
    else if (lastState == "PerformCPRState")
    {
        changeState(new PerformCPRState(this));
    }
}
