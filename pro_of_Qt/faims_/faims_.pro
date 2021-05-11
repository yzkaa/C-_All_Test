#-------------------------------------------------
#
# Project created by QtCreator 2019-04-28T19:21:01
#
#-------------------------------------------------

QT       += core gui serialport charts sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = faims
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    settingdialog.cpp \
    frminput.cpp

HEADERS += \
        mainwindow.h \
    settingdialog.h \
    frminput.h

FORMS += \
        mainwindow.ui \
    settingdialog.ui \
    frminput.ui

RESOURCES += \
    res.qrc

MOC_DIR         = temp/moc
RCC_DIR         = temp/rcc
UI_DIR          = temp/ui
OBJECTS_DIR     = temp/obj
DESTDIR         = bin

RC_ICONS += myapp.ico

DISTFILES += \
    test/style.qml

target.path = /home/pi/qt5
INSTALLS += target

CONFIG += qt debug warn_on
