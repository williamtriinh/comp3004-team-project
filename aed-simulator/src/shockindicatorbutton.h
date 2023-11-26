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
