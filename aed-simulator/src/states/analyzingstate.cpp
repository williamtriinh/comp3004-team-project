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
        if(context->getBattery()>=20){
            switch(getStep())
            {
            case 0:
            {
                if(context->getAnalyzingStateCounter()==0){
                    qDebug() << "Executing Analyzing State";
                    if(context->getPatientStatus() == MainWindow::PatientStatus::VHAB){
                        context->displayVTACHECG();
                    }

                    else if(context->getPatientStatus() == MainWindow::PatientStatus::VTACH){
                        context->displayVHABECG();
                    }
                    else{
                        context->displayNormalECG();
                    }
                }

                context->shockIndicatorButtonFlashing();
                context->playMessage("Give STAND CLEAR Warning. DO NOT touch patient");
                timer->start(ANALYZING_STATE_DURATION_MS);
                context->incrementAnalyzingStateCounter();
                break;
            }

            case 1:
                context->playMessage("Press Shock Indicator Button");
                timer->start(ANALYZING_STATE_DURATION_MS);
                break;

            case 2:

                while(!context->getShockIndicatorButtonPressed()){
                    QCoreApplication::processEvents();
                }
                context->playMessage("Shock will be delivered in three, two, one ....");
                timer->start(ANALYZING_STATE_DURATION_MS);
                break;

            case 3:
                context->playMessage("Shock delivered");
                context->setBattery(context->getBattery()-20);
                context->updateBattery();

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
                context->deactivateShockIndicatorButtonPressed();
                context->changeState(new PoweredOffState(context));
                return;
            }

            nextStep();
        }
        else{
            context->playMessage("Not enough battery to perform shock");
        }
    }
}

QString AnalyzingState::getStateName(){
    return "AnalyzingState";
}




