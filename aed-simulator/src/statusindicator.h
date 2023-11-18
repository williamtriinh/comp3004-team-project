#ifndef STATUSINDICATOR_H
#define STATUSINDICATOR_H

#include <QLabel>

/**
 * Represents the AED's status indicator.
 */
class StatusIndicator : public QLabel
{
    Q_OBJECT

public:
    explicit StatusIndicator(QWidget *parent = nullptr);
};

#endif // STATUSINDICATOR_H
