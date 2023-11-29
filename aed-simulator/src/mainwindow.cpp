#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "aedimage.h"
#include "powerbutton.h"
#include "shockindicatorbutton.h"
#include "statusindicator.h"

#include "graphs.h"

#include "simulation/attachelectrodepadswidget.h"
#include "simulation/batterieswidget.h"
#include "simulation/installelectrodeswidget.h"
#include "simulation/patientstatuswidget.h"
#include "simulation/endprogramwidget.h"



#include "states/poweredoffstate.h"

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

    // Set the initialize state
    state = new PoweredOffState(this);
    unitStatus = UnitStatus::DEFAULT;
    battery = 100;
    electrodesInstalled = true;
    electrodePadsAttachedState = ElectrodePadsAttachedState::NOT_ATTACHED;
    patientStatus = PatientStatus::DEFAULT;
    analyzingStateCounter = 0;
    numberOfShocks = battery/20;

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->setContentsMargins(0, 0, 0, 0);
    QWidget *leftWidget = new QWidget;
    leftWidget->setLayout(leftLayout);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->setContentsMargins(0, 0, 0, 0);
    QWidget *mainWidget = new QWidget;
    mainWidget->setLayout(mainLayout);

    QWidget *displayWidget = new QWidget;
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

    shockCountLabel = new QLabel(displayWidget);
    shockCountLabel->setText(QString("Shocks: %1").arg(numberOfShocks));
    shockCountLabel->move(DISPLAY_SIZE / 2 - 150, 220);

    ecgGraph = new QCustomPlot(displayWidget);
    ecgGraph->setFixedSize(300, 150);
    ecgGraph->move(DISPLAY_SIZE / 2 - 150, 240);
    ecgGraph->setStyleSheet("QWidget { background-color: black; }");

    shockIndicatorButton = new ShockIndicatorButton(displayWidget);
    shockIndicatorButton->move(DISPLAY_SIZE / 2 - shockIndicatorButton->width() / 2, 440);
    connect(shockIndicatorButton,SIGNAL(released()),this,SLOT(activateShockIndicatorButtonPressed()));


    StatusIndicator *statusIndicator = new StatusIndicator(this);
    bottomLayout->insertWidget(0, statusIndicator);


    TimerWidget *timerWidget = new TimerWidget(displayWidget);



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
    qDebug() << "MainWindow changeState() called with" << newState->getStateName();
    if (state != nullptr) {
        delete state;
    }
    state = newState;
    state->initialize();
    emit stateChanged(state);
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

void MainWindow::toggleElectrodesInstalled()
{
    electrodesInstalled = !electrodesInstalled;
    emit electrodesInstalledChanged(electrodesInstalled);
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

MainWindow::PatientStatus MainWindow::getPatientStatus()
{
    return patientStatus;
}

void MainWindow::setPatientStatus(PatientStatus status)
{
    patientStatus = status;
    emit patientStatusChanged(patientStatus);
}


void MainWindow::displayVTACHECG(){
    Graphs *graph = new Graphs(ecgGraph);
    graph->shockAdvisedECG();
}
void MainWindow::displayVHABECG(){
    Graphs *graph = new Graphs(ecgGraph);
    graph->shockAdvisedECG();
}

void MainWindow::displayNormalECG(){
    Graphs *graph = new Graphs(ecgGraph);
    graph->shockNotAdvisedECG();
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

void MainWindow::updateBattery(){
    numberOfShocks = battery/20;
    batteryLabel->setText(QString("Battery Level: %1%").arg(battery));
    shockCountLabel->setText(QString("Shocks: %1").arg(numberOfShocks));
}


void MainWindow::incrementAnalyzingStateCounter() {
    analyzingStateCounter++;
}

int MainWindow::getAnalyzingStateCounter() const{
    return analyzingStateCounter;
}



