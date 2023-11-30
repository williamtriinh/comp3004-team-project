#ifndef ELAPSEDTIMELABEL_H
#define ELAPSEDTIMELABEL_H

#include <QElapsedTimer>
#include <QWidget>
#include <QLabel>
#include <QTimer>

class ElapsedTimeLabel: public QWidget
{
public:
    ElapsedTimeLabel(QWidget *parent = nullptr);

    void startElapsedTime();
    qint64 getElapsedTime() const;
    void resetElapsedTime();

public slots:
    void updateElapsedTimeDisplay();

private:
    QElapsedTimer elapsedTimer;
    QLabel *elapsedTimeLabel;
    QTimer *updateTimer;
};

#endif // ELAPSEDTIMELABEL_H
