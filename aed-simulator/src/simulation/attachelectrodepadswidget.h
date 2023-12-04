#ifndef ATTACHELECTRODEPADSWIDGET_H
#define ATTACHELECTRODEPADSWIDGET_H

#include <QComboBox>
#include <QWidget>

class MainWindow;

class AttachElectrodePadsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AttachElectrodePadsWidget(MainWindow *mainWindow, QWidget *parent = nullptr);

private:
    MainWindow *mainWindow;

    QComboBox *patientComboBox;
    QComboBox *attachmentComboBox;

private slots:
    void handlePatientComboBoxChanged(int index);
    void handleAttachmentComboBoxChanged(int index);

signals:
    void buttonClicked();
};

#endif // ATTACHELECTRODEPADSWIDGET_H
