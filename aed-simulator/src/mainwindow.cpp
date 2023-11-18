#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "aedimage.h"
#include <QLabel>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->displayWidget->setFixedSize(DISPLAY_SIZE, DISPLAY_SIZE);

    AEDImage *greenRingImage = new AEDImage(":/images/green_ring.png", DISPLAY_SIZE - 94, ui->displayWidget);
    greenRingImage->move(DISPLAY_SIZE / 2 - greenRingImage->width() / 2, DISPLAY_SIZE / 2 - greenRingImage->height() / 2);

    AEDImage *image1 = new AEDImage(":/images/steps/01_check_responsiveness.png", 120, ui->displayWidget);
    image1->move(10, 210);

    AEDImage *image2 = new AEDImage(":/images/steps/02_call_emergency.png", 120, ui->displayWidget);
    image2->move(DISPLAY_SIZE / 2 - image2->width() / 2, 20);

    AEDImage *image3 = new AEDImage(":/images/steps/03_attach_pads.png", 120, ui->displayWidget);
    image3->move(DISPLAY_SIZE - image3->width() - 10, 270);

    AEDImage *image4 = new AEDImage(":/images/steps/04_dont_touch_patient.png", 120, ui->displayWidget);
    image4->move(DISPLAY_SIZE - image4->width() - 160, 540);

    AEDImage *image5 = new AEDImage(":/images/steps/05_start_cpr.png", 200, ui->displayWidget);
    image5->move(80, 460);
}

MainWindow::~MainWindow()
{
    delete ui;
}

