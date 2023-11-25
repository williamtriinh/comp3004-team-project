#ifndef STATUSINDICATOR_H
#define STATUSINDICATOR_H

#include <QLabel>
#include <QPixmap>

class MainWindow;

/**
 * Represents the AED's status indicator.
 */
class StatusIndicator : public QLabel
{
    Q_OBJECT

public:
    explicit StatusIndicator(MainWindow *mainWindow, QWidget *parent = nullptr);

private:
    MainWindow *mainWindow;

    QPixmap offPixmap;
    QPixmap failedPixmap;
    QPixmap passedPixmap;

private slots:
    void updateIndicator();
};

#endif // STATUSINDICATOR_H
