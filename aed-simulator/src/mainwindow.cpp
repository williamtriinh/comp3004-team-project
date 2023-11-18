#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "aedimage.h"
#include "powerbutton.h"
#include "statusindicator.h"

#include <QComboBox>
#include <QHBoxLayout>
#include <QPlainTextEdit>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

    AEDImage *greenRingImage = new AEDImage(":/images/green_ring.png", DISPLAY_SIZE - 94, displayWidget);
    greenRingImage->move(DISPLAY_SIZE / 2 - greenRingImage->width() / 2, DISPLAY_SIZE / 2 - greenRingImage->height() / 2);

    AEDImage *image1 = new AEDImage(":/images/steps/01_check_responsiveness.png", 120, displayWidget);
    image1->move(10, 210);

    AEDImage *image2 = new AEDImage(":/images/steps/02_call_emergency.png", 120, displayWidget);
    image2->move(DISPLAY_SIZE / 2 - image2->width() / 2, 20);

    AEDImage *image3 = new AEDImage(":/images/steps/03_attach_pads.png", 120, displayWidget);
    image3->move(DISPLAY_SIZE - image3->width() - 10, 270);

    AEDImage *image4 = new AEDImage(":/images/steps/04_dont_touch_patient.png", 120, displayWidget);
    image4->move(DISPLAY_SIZE - image4->width() - 160, 540);

    AEDImage *image5 = new AEDImage(":/images/steps/05_start_cpr.png", 200, displayWidget);
    image5->move(80, 460);

    StatusIndicator *statusIndicator = new StatusIndicator;
    bottomLayout->insertWidget(0, statusIndicator);

    PowerButton *powerButton = new PowerButton();
    bottomLayout->insertWidget(2, powerButton);

    // Widgets for simulating events/actions
    QVBoxLayout *rightLayout = new QVBoxLayout;
    QWidget *rightWidget = new QWidget();
    rightWidget->setLayout(rightLayout);
    rightWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QComboBox *electrodePadsComboBox = new QComboBox;
    electrodePadsComboBox->addItem("success");
    electrodePadsComboBox->addItem("failure");
    rightLayout->addWidget(electrodePadsComboBox);

    QPushButton *electrodePadsButton = new QPushButton("Apply Electrode Pads");
    rightLayout->addWidget(electrodePadsButton);
    rightLayout->addStretch();

    QPlainTextEdit *audioConsole = new QPlainTextEdit;
    audioConsole->setReadOnly(true);
    rightLayout->addWidget(audioConsole);

    mainLayout->addWidget(rightWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

