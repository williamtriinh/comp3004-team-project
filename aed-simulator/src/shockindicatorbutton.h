//#ifndef SHOCKINDICATORBUTTON_H
//#define SHOCKINDICATORBUTTON_H

//#include <QPixmap>
//#include <QPushButton>
//#include <QWidget>

///**
// * Represents the AED's shock indicator. Light indicator flashes when a shock is ready.
// */
//class ShockIndicatorButton : public QPushButton
//{
//    Q_OBJECT
//public:
//    ShockIndicatorButton(QWidget *parent);
//    void toggleLight();

//private:
//    QPixmap onPixmap;
//    QPixmap offPixmap;
//};

//#endif // SHOCKINDICATORBUTTON_H

#ifndef SHOCKINDICATORBUTTON_H
#define SHOCKINDICATORBUTTON_H

#include <QPushButton>
#include <QPixmap>
#include <QTimer>

class ShockIndicatorButton : public QPushButton
{
    Q_OBJECT

public:
    explicit ShockIndicatorButton(QWidget *parent = nullptr);
    void startFlashing();
    void stopFlashing();


private slots:
    void toggleLight();

private:
    QPixmap offPixmap;
    QPixmap onPixmap;
    QTimer *timer;
    bool illuminated;

};

#endif // SHOCKINDICATORBUTTON_H
