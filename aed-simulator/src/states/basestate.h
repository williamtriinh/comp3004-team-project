#ifndef BASESTATE_H
#define BASESTATE_H

#include <QObject>

class MainWindow;

/**
 * An abstract class representing the base state of the AED
 */

class BaseState : public QObject
{
    Q_OBJECT
public:
    BaseState(MainWindow *context);
    virtual ~BaseState();

    /**
     * The method that's called when the context transitions into the corresponding state.
     * Only called once.
     */
    virtual void initialize();

    /**
     * For debugging purposes. Returns the name of the state.
     * @return The name of the corresponding state
     */
    virtual QString getStateName() = 0;

public slots:
    /**
     * The main execution method for the state. Can be called multiple times.
     */
    virtual void execute();

    /**
     * Handles turning on/off the AED.
     */
    virtual void togglePower();
protected:
    MainWindow *context;
};

#endif // BASESTATE_H
