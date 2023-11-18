#ifndef SHOCKINDICATORBUTTON_H
#define SHOCKINDICATORBUTTON_H

#include <QPixmap>
#include <QPushButton>
#include <QWidget>

class ShockIndicatorButton : public QPushButton
{
    Q_OBJECT
public:
    ShockIndicatorButton(QWidget *parent);

private:
    QPixmap onPixmap;
    QPixmap offPixmap;
};

#endif // SHOCKINDICATORBUTTON_H
