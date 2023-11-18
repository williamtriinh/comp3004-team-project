#ifndef STATUSINDICATOR_H
#define STATUSINDICATOR_H

#include <QLabel>
#include <QPixmap>

/**
 * Represents the AED's status indicator.
 */
class StatusIndicator : public QLabel
{
    Q_OBJECT

public:
    explicit StatusIndicator(QWidget *parent = nullptr);

private:
    QPixmap offPixmap;
    QPixmap failedPixmap;
    QPixmap passedPixmap;
};

#endif // STATUSINDICATOR_H
