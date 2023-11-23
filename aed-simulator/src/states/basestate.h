#ifndef BASESTATE_H
#define BASESTATE_H

#include <QObject>

class MainWindow; // Forward declaration

/**
 * An abstract class representing the base state of the AED
 */

class BaseState : public QObject
{
    Q_OBJECT

public slots:
    void setContext(MainWindow *context);
    virtual void execute() = 0;
    virtual void togglePower() = 0;
protected:
    MainWindow *context;
};

#endif // BASESTATE_H
