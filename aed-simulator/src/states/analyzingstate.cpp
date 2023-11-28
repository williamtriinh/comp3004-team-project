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
                if(context->getPatientStatus() == MainWindow::PatientStatus::VHAB){
                    context->displayVTACHECG();
                }

                else if(context->getPatientStatus() == MainWindow::PatientStatus::VTACH){
                    context->displayVHABECG();
                }
                else{
                    context->displayNormalECG();
                }

                context->shockIndicatorButtonFlashing();
                context->playMessage("Give STAND CLEAR Warning. DO NOT touch patient");
                timer->start(SELF_TEST_DURATION_MS);
                break;
            }

            case 1:
                context->playMessage("Press Shock Indicator Button");
                timer->start(SELF_TEST_DURATION_MS);
                break;

            case 2:

                while(!context->getShockIndicatorButtonPressed()){
                    QCoreApplication::processEvents();
                }
                context->playMessage("Shock will be delivered in three, two, one ....");
                timer->start(SELF_TEST_DURATION_MS);
                break;

            case 3:
                context->playMessage("Shock delivered");
                context->setBattery(context->getBattery()-20);
                context->updateBattery();
                timer->start(SELF_TEST_DURATION_MS);
                break;

            case 4:
                context->shockIndicatorButtonStopFlashing();
                context->deactivateShockIndicatorButtonPressed();
                context->changeState(new PerformCPRState(context));
                return;
            }

            nextStep();
        }
        else{
            context->playMessage("Not enough battery");
        }
    }
}

QString AnalyzingState::getStateName(){
    return "AnalyzingState";
}




