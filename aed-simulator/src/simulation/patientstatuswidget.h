#ifndef PATIENTSTATUSWIDGET_H
#define PATIENTSTATUSWIDGET_H


#include <QComboBox>
#include <QWidget>

class MainWindow;

class PatientStatusWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PatientStatusWidget(MainWindow *mainWindow, QWidget *parent = nullptr);

private:

    MainWindow *mainWindow;

    QComboBox *patientStatusComboBox;

private slots:
    void handlePatientStatusComboBoxChanged(int index);

signals:
    void buttonClicked();
};

#endif
