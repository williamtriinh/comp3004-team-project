#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "aedimage.h"
#include "powerbutton.h"
#include "shockindicatorbutton.h"
#include "statusindicator.h"

#include "simulation/batterieswidget.h"
#include "simulation/installelectrodeswidget.h"
#include "states/poweredoffstate.h"

#include <QComboBox>
#include <QDebug>
#include <QHBoxLayout>
#include <QLabel>
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
    state = NULL;
    changeState(new PoweredOffState(this));

    unitStatus = UnitStatus::DEFAULT;
    battery = 100;
    electrodesInstalled = true;

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

//    AEDImage *greenRingImage = new AEDImage(":/images/green_ring.png", DISPLAY_SIZE - 94, displayWidget);
//    greenRingImage->move(DISPLAY_SIZE / 2 - greenRingImage->width() / 2, DISPLAY_SIZE / 2 - greenRingImage->height() / 2);

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

    QLabel *batteryLabel = new QLabel("Battery Level: 100%", displayWidget);
    batteryLabel->move(DISPLAY_SIZE / 2 - 150, 200);
    QLabel *shockCountLabel = new QLabel("Shocks: 05", displayWidget);
    shockCountLabel->move(DISPLAY_SIZE / 2 - 150, 220);

    QWidget *placeholderGraph = new QWidget(displayWidget);
    placeholderGraph->setFixedSize(300, 150);
    placeholderGraph->move(DISPLAY_SIZE / 2 - 150, 240);
    placeholderGraph->setStyleSheet("QWidget { background-color: black; }");

    ShockIndicatorButton *shockIndicatorButton = new ShockIndicatorButton(displayWidget);
    shockIndicatorButton->move(DISPLAY_SIZE / 2 - shockIndicatorButton->width() / 2, 440);

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

    rightLayout->addWidget(new BatteriesWidget(this));
    rightLayout->addWidget(new InstallElectrodesWidget(this));

    // Applying electro pads to victim
    QComboBox *electrodePadsComboBox = new QComboBox;
    electrodePadsComboBox->addItem("success");
    electrodePadsComboBox->addItem("failure");
    rightLayout->addWidget(electrodePadsComboBox);

    QPushButton *electrodePadsButton = new QPushButton("Apply Electrode Pads");
    rightLayout->addWidget(electrodePadsButton);
    rightLayout->addStretch();

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
    battery = std::clamp(value, 0, 100);
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
