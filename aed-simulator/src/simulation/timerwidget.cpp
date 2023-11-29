#ifndef TIMERWIDGET_H
#define TIMERWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QLabel>
#include <QPushButton>
#include <QDateTime>

class TimerWidget : public QWidget {
    Q_OBJECT

public:
    explicit TimerWidget(QWidget *parent = nullptr);

private slots:
    void startTimer();
    void stopTimer();
    void updateTime();

private:
    QTimer *timer;
    QLabel *timeLabel;
    QDateTime startTime;
};

#endif // TIMERWIDGET_H
