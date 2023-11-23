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
    src/states/analyzingstate.cpp \
    src/states/attachdefibrillatorpadsstate.cpp \
    src/states/basestate.cpp \
    src/states/callforhelpstate.cpp \
    src/states/checkresponsivenessstate.cpp \
    src/states/performcprstate.cpp \
    src/states/poweredoffstate.cpp \
    src/states/poweredonstate.cpp \
    src/states/selfteststate.cpp \
    src/statusindicator.cpp

HEADERS += \
    src/aedimage.h \
    src/mainwindow.h \
    src/powerbutton.h \
    src/shockindicatorbutton.h \
    src/states/analyzingstate.h \
    src/states/attachdefibrillatorpadsstate.h \
    src/states/basestate.h \
    src/states/callforhelpstate.h \
    src/states/checkresponsivenessstate.h \
    src/states/performcprstate.h \
    src/states/poweredoffstate.h \
    src/states/poweredonstate.h \
    src/states/selfteststate.h \
    src/statusindicator.h

FORMS += \
    src/mainwindow.ui

RESOURCES = application.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
