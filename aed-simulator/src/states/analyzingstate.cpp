#include "analyzingstate.h"
#include "../mainwindow.h"

#include "../mainwindow.h"

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
        // Show Graph
        return;
    }
    else if(context->getPatientStatus() == MainWindow::PatientStatus::VTACH){
        // Show Graph
        return;
    }
    else{
        // Show Graph
        return;
    }
}


QString AnalyzingState::getStateName()
{
    return "AnalyzingState";
}
