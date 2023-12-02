#include "analyzingstate.h"

#include "../mainwindow.h"
#include "lowbatterystate.h"
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
    if(context->getPatientStatus() == MainWindow::PatientStatus::DEFAULT){
        qDebug() << "Select Patient's Status";
        while(context->getPatientStatus() == MainWindow::PatientStatus::DEFAULT) {
            QCoreApplication::processEvents();
        }
    }
    switch(getStep())
    {
    case 0:
    {
        if(context->getAnalyzingStateCounter()==0){
            qDebug() << "Executing Analyzing State";
            if(context->getPatientStatus() == MainWindow::PatientStatus::VT){
                qDebug() << "1";
                context->displayVTECG();
            }
            else if(context->getPatientStatus() == MainWindow::PatientStatus::VF){
                context->displayVFECG();
                qDebug() << "2";
            }
            else if(context->getPatientStatus() == MainWindow::PatientStatus::PEA){
                context->displayPEAECG();
                if(context->getDeathStatus() != true){
                    context->changeState(new PerformCPRState(context));
                    return;
                }
                qDebug() << "3";
            }
            else if(context->getPatientStatus() == MainWindow::PatientStatus::ASYSTOLE){
                qDebug() << "4";
                context->displayAsystoleECG();
                if(context->getDeathStatus() != true){
                    context->changeState(new PerformCPRState(context));
                    return;
                }

                return;
            }
        }
        if(context->getBattery() >= MainWindow::SHOCK_BATTERY_COST){
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
        context->setBattery(context->getBattery() - MainWindow::SHOCK_BATTERY_COST);
        context->updateShockCount();
        timer->start(1000);
        break;

    case 4:

        if (context->getBattery() == 0)
        {
            context->playMessage("Battery Reached 0.");
            context->changeState(new PoweredOffState(context));
            return;
        }

        if (!context->hasSufficientBattery())
        {
            context->changeState(new LowBatteryState(context));
            return;
        }

        timer->start(1000);
        break;

    case 5:
        context->shockIndicatorButtonStopFlashing();
        if(context->getDeathStatus() != true){
            context->changeState(new PerformCPRState(context));
            return;
        }
    }

    nextStep();


}

QString AnalyzingState::getStateName(){
    return "AnalyzingState";
}




