#-------------------------------------------------
#
# Project created by QtCreator 2019-03-06T11:53:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qetchosts
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    highlighter.cpp \
    settingsdialog.cpp \
    hostslistitem.cpp \
    hostslistmodel.cpp \
    aboutdialog.cpp \
    adddialog.cpp \
    editor/codeeditor.cpp

HEADERS += \
        mainwindow.h \
    highlighter.h \
    settingsdialog.h \
    hostslistitem.h \
    hostslistmodel.h \
    consts.h \
    aboutdialog.h \
    adddialog.h \
    editor/codeeditor.h

FORMS += \
        mainwindow.ui \
    settingsdialog.ui \
    aboutdialog.ui \
    adddialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc
