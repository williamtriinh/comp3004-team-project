#ifndef POWERBUTTON_H
#define POWERBUTTON_H

#include <QPushButton>
#include <QObject>

/**
 * Represents the AED's power button. It turns on/off the device.
 */
class PowerButton : public QPushButton
{
    Q_OBJECT
public:
    PowerButton();
};

#endif // POWERBUTTON_H
