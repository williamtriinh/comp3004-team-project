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
    if(context->getPatientStatus() == MainWindow::PatientStatus::VHAB){

        context->displayVTACHECG();

    }
    else if(context->getPatientStatus() == MainWindow::PatientStatus::VTACH){
        context->displayVHABECG();

    }
    else if(context->getPatientStatus() == MainWindow::PatientStatus::NORMAL){
        context->displayNormalECG();

    }
    else{
        qDebug() << "Select Patient's Status";
    }


    context->changeState(new PerformCPRState(context));
}


QString AnalyzingState::getStateName()
{
    return "AnalyzingState";
}
