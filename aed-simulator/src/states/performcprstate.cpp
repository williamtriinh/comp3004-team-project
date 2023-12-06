#include "performcprstate.h"
#include "../mainwindow.h"
#include "analyzingstate.h"
#include "poweredoffstate.h"

PerformCPRState::PerformCPRState(MainWindow *context)
    : BaseState(context)
{
    timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, &QTimer::timeout, this, &PerformCPRState::execute);
}

PerformCPRState::~PerformCPRState()
{
    delete timer;
}

void PerformCPRState::initialize()
{
    context->playMessage("Perform CPR.");
    context->playMessage("2 breaths for every 30 compressions.");
    context->getChestCompressionDisplay()->setCompressionTypeIndex(0);
    context->getChestCompressionDisplay()->setVisible(true);
    timer->start(2000);
}

void PerformCPRState::execute()
{
    switch (getStep()) {
    case 0:
        context->playMessage("Compression too deep. Reduce force.");
        context->getChestCompressionDisplay()->setCompressionTypeIndex(3);
        timer->start(2000);
        break;

    case 1:
        context->playMessage("Compression too shallow. Press harder.");
        context->getChestCompressionDisplay()->setCompressionTypeIndex(1);
        timer->start(2000);
        break;

    case 2:
        context->playMessage("Good compression depth. Keep going.");
        context->getChestCompressionDisplay()->setCompressionTypeIndex(2);
        timer->start(5000);
        break;

    case 3:
        if(context->getEndOfProgramStatus() == MainWindow::EndOfProgramStatus::CPRREVIVESPATIENT){
            context->displayPEAECG();
            context->playMessage("CPR Revived Patient. AED Shutting Off");
            timer->start(3000);
        }
        timer->start(10);
        break;
    case 4:
        if(context->getEndOfProgramStatus() == MainWindow::EndOfProgramStatus::CPRREVIVESPATIENT){
            context->changeState(new PoweredOffState(context));
            return;
        }
        timer->start(10);
        break;


    case 5:
        context->playMessage("Stop CPR.");
        context->getChestCompressionDisplay()->setVisible(false);
        context->changeState(new AnalyzingState(context));
        return;
    }
    nextStep();
}

QString PerformCPRState::getStateName()
{
    return "PerformCPRState";
}
