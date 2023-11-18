QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/aedimage.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/powerbutton.cpp \
    src/shockindicatorbutton.cpp \
    src/statusindicator.cpp

HEADERS += \
    src/aedimage.h \
    src/mainwindow.h \
    src/powerbutton.h \
    src/shockindicatorbutton.h \
    src/statusindicator.h

FORMS += \
    src/aedimage.ui \
    src/mainwindow.ui \
    src/statusindicator.ui

RESOURCES = application.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
