#ifndef STATUSINDICATOR_H
#define STATUSINDICATOR_H

#include <QWidget>

namespace Ui {
class StatusIndicator;
}

/**
 * Represents the AED's status indicator.
 */
class StatusIndicator : public QWidget
{
    Q_OBJECT

public:
    explicit StatusIndicator(QWidget *parent = nullptr);
    ~StatusIndicator();

private:
    Ui::StatusIndicator *ui;
};

#endif // STATUSINDICATOR_H
