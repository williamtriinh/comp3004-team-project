#include "analyzingstate.h"
#include "../mainwindow.h"
#include "performcprstate.h"

#include <QCoreApplication>

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
    timer->start(SELF_TEST_DURATION_MS);
}



void AnalyzingState::execute()
{
    bool shockAdvised = true;


    if(context->getPatientStatus() == MainWindow::PatientStatus::DEFAULT){
        qDebug() << "Select Patient's Status";
        while(context->getPatientStatus() == MainWindow::PatientStatus::DEFAULT) {

            QCoreApplication::processEvents();
            QThread::msleep(100);
        }

    }




    if(context->getPatientStatus() == MainWindow::PatientStatus::VHAB){
        context->displayVTACHECG();
    }

    else if(context->getPatientStatus() == MainWindow::PatientStatus::VTACH){
        context->displayVHABECG();
    }

    else{
        context->displayNormalECG();
        shockAdvised = false;
    }

    if(shockAdvised){
        if(context->getBattery()>10){
            switch(getStep())
            {

            case 0:
            {
                context->shockIndicatorButtonFlashing();
                context->playMessage("Give STAND CLEAR Warning. DO NOT touch patient");

            }
            case 1:

                context->playMessage("Shock will be delivered in three, two, one ....");



            case 2:
                context->playMessage("Shock delivered");
                context->setBattery(context->getBattery()-10);

            }
            nextStep();
        }
        else{
            context->playMessage("Not enough battery");
        }


        context->shockIndicatorButtonStopFlashing();
        context->changeState(new PerformCPRState(context));
    }
}



QString AnalyzingState::getStateName(){
    return "AnalyzingState";
}




