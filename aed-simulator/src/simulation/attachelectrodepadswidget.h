#ifndef ATTACHELECTRODEPADSWIDGET_H
#define ATTACHELECTRODEPADSWIDGET_H

#include <QComboBox>
#include <QPushButton>
#include <QWidget>

class MainWindow;

class AttachElectrodePadsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AttachElectrodePadsWidget(MainWindow *mainWindow, QWidget *parent = nullptr);

private:
    QComboBox *patientComboBox;
    QComboBox *attachmentComboBox;
    QPushButton *button;

signals:

};

#endif // ATTACHELECTRODEPADSWIDGET_H
