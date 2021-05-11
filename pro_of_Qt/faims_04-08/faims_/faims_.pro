#-------------------------------------------------
#
# Project created by QtCreator 2019-04-28T19:21:01
#
#-------------------------------------------------

QT       += core gui serialport charts sql
QT += network
QT += concurrent
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = faims_
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
    frminput.cpp \
    spectrogramdialog.cpp \
    utils.cpp \
    DataBase/databasedialog.cpp \
    serverdialog.cpp \
    DataBase/databaseserver.cpp \
    DataBase/relationmode.cpp \
    DataBase/spectrogramrelationmode.cpp \
    DataBase/fingerprintrelationmode.cpp \
    DataBase/warehousingrelationmode.cpp \
    DataBase/databasethread.cpp \
    DataBase/databaseinsertdialog.cpp \
    DataBase/databaseconnectdialog.cpp \
    allsettingsdialog.cpp \
    DataBase/spectrogramfilterdialog.cpp \
    UDP/networkserver.cpp \
    UDP/udpthread.cpp \
    networksettingsdialog.cpp

HEADERS += \
        mainwindow.h \
    settingdialog.h \
    frminput.h \
    spectrogramdialog.h \
    utils.h \
    DataBase/databasedialog.h \
    serverdialog.h \
    DataBase/databaseserver.h \
    DataBase/relationmode.h \
    DataBase/spectrogramrelationmode.h \
    DataBase/fingerprintrelationmode.h \
    DataBase/warehousingrelationmode.h \
    DataBase/databasethread.h \
    systemsettings.h \
    DataBase/databaseinsertdialog.h \
    DataBase/databaseconnectdialog.h \
    DataBase/dbdatas.h \
    allsettingsdialog.h \
    DataBase/spectrogramfilterdialog.h \
    UDP/networkserver.h \
    UDP/udpthread.h \
    params.h \
    networksettingsdialog.h

FORMS += \
        mainwindow.ui \
    settingdialog.ui \
    frminput.ui \
    spectrogramdialog.ui \
    DataBase/databasedialog.ui \
    serverdialog.ui \
    DataBase/databaseinsertdialog.ui \
    DataBase/databaseconnectdialog.ui \
    allsettingsdialog.ui \
    DataBase/spectrogramfilterdialog.ui \
    networksettingsdialog.ui

RESOURCES += \
    res.qrc

MOC_DIR         = temp/moc
RCC_DIR         = temp/rcc
UI_DIR          = temp/ui
OBJECTS_DIR     = temp/obj
DESTDIR         = bin


RC_ICONS += myapp.ico

#LIBS += -L"/home/glch/project/faims_/qwt/lib" -lqwtd
#LIBS += -L"/home/yzk/C++/pro_of_Qt/faims_04-08/faims_/qwt/lib" -lqwt
#INCLUDEPATH += /home/yzk/C++/pro_of_Qt/faims_04-08/faims_/qwt/src
INCLUDEPATH += /usr/local/qwt-6.1.5.ARM/include
LIBS += -L/usr/local/qwt-6.1.5.ARM/lib -lqwt
#CONFIG += qaxcontainer


# excel库 1.3.7
#QXLSX_PARENTPATH = /home/glch/project/faims_/QXlsx/ # current QXlsx path is . (. means curret directory)
#QXLSX_HEADERPATH = /home/glch/project/faims_/QXlsx/header/  # current QXlsx header path is ./header/
#QXLSX_SOURCEPATH = /home/glch/project/faims_/QXlsx/source/  # current QXlsx source path is ./source/
#include(/home/glch/project/faims_/QXlsx/QXlsx.pri)

DISTFILES += \
    res/create_database.sql \
    res/FAIMS_init.sql

target.path = /home/pi/Desktops/
INSTALLS += target


