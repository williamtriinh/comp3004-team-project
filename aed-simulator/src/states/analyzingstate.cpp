#include "analyzingstate.h"
#include "../mainwindow.h"
#include "performcprstate.h"

AnalyzingState::AnalyzingState(MainWindow *context)
    : BaseState(context)
{
    timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, &QTimer::timeout, this, &AnalyzingState::execute);
}

AnalyzingState::~AnalyzingState()
{
    delete timer;
}

void AnalyzingState::initialize(){
    context->playMessage("Don't touch patient. Analyzing");
    timer->start(5000);
}



void AnalyzingState::execute()
{
    bool shockAdvised = true;
    while(context->getPatientStatus() == MainWindow::PatientStatus::DEFAULT){
        if(context->getPatientStatus() == MainWindow::PatientStatus::VHAB){

            context->displayVTACHECG();

        }
        else if(context->getPatientStatus() == MainWindow::PatientStatus::VTACH){
            context->displayVHABECG();

        }
        else if(context->getPatientStatus() == MainWindow::PatientStatus::NORMAL){
            context->displayNormalECG();
            shockAdvised = false;

        }
        else{
            qDebug() << "Select Patient's Status";
            timer->start(3000);
        }
    }
    if(shockAdvised){
        if(context->getBattery()>10){
            context->playMessage("Give STAND CLEAR Warning. SO NOT touch patient");
            timer->start(3000);
            context->playMessage("Shock will be delivered in three, two, one ....");
            timer->start(1000);
            context->playMessage("Shock delivered");
            timer->start(1000);
            context->setBattery(context->getBattery()-10);
        }
        else{
            context->playMessage("Not enough battery");
            timer->start(1000);
        }
    }


    context->changeState(new PerformCPRState(context));
}


QString AnalyzingState::getStateName()
{
    return "AnalyzingState";
}
