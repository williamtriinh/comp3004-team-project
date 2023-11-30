#include "analyzingstate.h"
#include "../mainwindow.h"
#include "performcprstate.h"
#include "poweredoffstate.h"

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
    timer->start(ANALYZING_STATE_DURATION_MS);
}

void AnalyzingState::execute()
{
    bool shockAdvised = true;
    if(context->getPatientStatus() == MainWindow::PatientStatus::DEFAULT){
        qDebug() << "Select Patient's Status";
        while(context->getPatientStatus() == MainWindow::PatientStatus::DEFAULT) {
            QCoreApplication::processEvents();
        }
    }

    if(context->getPatientStatus() == MainWindow::PatientStatus::DEFAULT){
        shockAdvised = false;
    }

    if(shockAdvised){

        switch(getStep())
        {
        case 0:
        {
            if(context->getAnalyzingStateCounter()==0){
                qDebug() << "Executing Analyzing State";
                if(context->getPatientStatus() == MainWindow::PatientStatus::VT){
                    context->displayVTECG();
                }

                else if(context->getPatientStatus() == MainWindow::PatientStatus::VF){
                    context->displayVFECG();
                }
                else if(context->getPatientStatus() == MainWindow::PatientStatus::PEA){
                    context->displayPEAECG();
                }
                else{
                    context->displayAsystoleECG();
                }

            }
            if(context->getBattery()>=20){

                context->shockIndicatorButtonFlashing();
                context->playMessage("Give STAND CLEAR Warning. DO NOT touch patient");
                timer->start(ANALYZING_STATE_DURATION_MS);
                context->incrementAnalyzingStateCounter();
                break;
            }
            else{
                context->playMessage("Not enough battery to perform shock");
                return;
            }


        }

        case 1:
            context->playMessage("Press Shock Indicator Button");
            timer->start(ANALYZING_STATE_DURATION_MS);
            break;

        case 2:

            while(!context->getShockIndicatorButtonPressed()){
                QCoreApplication::processEvents();
            }
            context->deactivateShockIndicatorButtonPressed();
            context->playMessage("Shock will be delivered in three, two, one ....");
            timer->start(ANALYZING_STATE_DURATION_MS);
            break;

        case 3:

            context->playMessage("Shock delivered");
            context->setBattery(context->getBattery()-10);
            context->updateBattery();
            context->updateShockCount();
            timer->start(1000);
            break;

        case 4:

            if(context->getBattery()==0){
                context->playMessage("Battery Reached 0. Powering Off");
                context->changeState(new PoweredOffState(context));
            }
            timer->start(1000);
            break;

        case 5:
            context->shockIndicatorButtonStopFlashing();
            context->changeState(new PerformCPRState(context));
            return;
        }

        nextStep();
    }

}

QString AnalyzingState::getStateName(){
    return "AnalyzingState";
}




