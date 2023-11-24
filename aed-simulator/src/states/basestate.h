#ifndef BASESTATE_H
#define BASESTATE_H

#include <QObject>
#include <QTimer>

class MainWindow; // Forward declaration

/**
 * An abstract class representing the base state of the AED
 */

class BaseState : public QObject
{
    Q_OBJECT


public:
    BaseState(MainWindow *context);
    ~BaseState();

public slots:
    /**
     * The method that's called when the context transitions into the corresponding state.
     */
    virtual void execute() = 0;

    /**
     * Handles turning on/off the AED.
     */
    virtual void togglePower() = 0;
protected:
    MainWindow *context;
    QTimer *timer;
};

#endif // BASESTATE_H
