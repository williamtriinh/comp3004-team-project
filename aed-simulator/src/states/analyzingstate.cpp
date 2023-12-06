#include "analyzingstate.h"

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
    switch(getStep())
    {
    case 0:
        if (context->getPatientStatus() == MainWindow::PatientStatus::DEFAULT)
        {
            qDebug() << "Select Patient Status";
            timer->start(100);
            return;
        }
        timer->start(100);
        break;
    case 1:
    {
        if(context->getPatientStatus() == MainWindow::PatientStatus::VT){
            context->displayVTECG();
        }
        else if(context->getPatientStatus() == MainWindow::PatientStatus::VF){
            context->displayVFECG();
        }
        else if(context->getPatientStatus() == MainWindow::PatientStatus::PEA){
            context->displayPEAECG();
            context->playMessage("No Shock Is Advised");
            context->changeState(new PerformCPRState(context));
            return;
        }
        else if(context->getPatientStatus() == MainWindow::PatientStatus::ASYSTOLE){
            context->displayAsystoleECG();
            context->playMessage("No Shock Is Advised");
            context->changeState(new PerformCPRState(context));
            return;
        }

        if(context->getBattery() >= MainWindow::SHOCK_BATTERY_COST){
            context->shockIndicatorButtonFlashing();
            context->playMessage("Give STAND CLEAR Warning. DO NOT touch patient");
            timer->start(ANALYZING_STATE_DURATION_MS);
            break;
        }

        else{
            context->playMessage("Not enough battery to perform shock");
            return;
        }
    }

    case 2:
        context->deactivateShockIndicatorButtonPressed();
        context->playMessage("Press Shock Indicator Button");
        timer->start(ANALYZING_STATE_DURATION_MS);
        break;

    case 3:

        if (!context->getShockIndicatorButtonPressed())
        {
            timer->start(100);
            return;
        }
        context->deactivateShockIndicatorButtonPressed();
        context->playMessage("Shock will be delivered in three, two, one ....");
        timer->start(ANALYZING_STATE_DURATION_MS);
        break;

    case 4:
        context->playMessage("Shock delivered");
        context->setBattery(context->getBattery() - MainWindow::SHOCK_BATTERY_COST);
        context->updateShockCount();
        if(context->getEndOfProgramStatus() == MainWindow::EndOfProgramStatus::SHOCKREVIVESPATIENT){
            context->displayPEAECG();
            context->playMessage("Shock Revived Patient. AED Shutting Off");
        }

        timer->start(3000);
        break;

    case 5:

        if(context->getEndOfProgramStatus() == MainWindow::EndOfProgramStatus::SHOCKREVIVESPATIENT){
            context->changeState(new PoweredOffState(context));
            return;
        }

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

    case 6:
        context->shockIndicatorButtonStopFlashing();
        context->changeState(new PerformCPRState(context));
        return;
    }

    nextStep();


}

QString AnalyzingState::getStateName(){
    return "AnalyzingState";
}






