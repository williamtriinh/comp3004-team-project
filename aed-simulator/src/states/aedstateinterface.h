#ifndef AEDSTATEINTERFACE_H
#define AEDSTATEINTERFACE_H

#include <QObject>

class MainWindow;

class AEDStateInterface : public QObject
{
    Q_OBJECT

public slots:
    void setContext(MainWindow *context);
    virtual void execute() = 0;
    virtual void togglePower() = 0;
protected:
    MainWindow *context;
};

#endif // AEDSTATEINTERFACE_H
