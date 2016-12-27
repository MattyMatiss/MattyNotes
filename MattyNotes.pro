#-------------------------------------------------
#
# Project created by QtCreator 2016-12-14T13:26:52
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MattyNotes
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mattynotesmainwindow.cpp \
    addnotedialog.cpp \
    mattysettingsdialog.cpp \
    constants.cpp \
    dbmanager.cpp \
    mattyclocks.cpp \
    mattygroupbox.cpp \
    mattymessagebox.cpp \
    mattynote.cpp \
    mattystylesheeteditor.cpp \
    noteholder.cpp \
    queryconstructor.cpp \
    utilityfunctions.cpp

HEADERS  += dbmanager.h \
    mattynotesmainwindow.h \
    addnotedialog.h \
    mattysettingsdialog.h \
    constants.h \
    mattyclocks.h \
    mattygroupbox.h \
    mattymessagebox.h \
    mattynote.h \
    mattystylesheeteditor.h \
    noteholder.h \
    queryconstructor.h \
    utilityfunctions.h \

RESOURCES += \
    mattynotesmainwindow.qrc

message($$OUT_PWD)

CONFIG -= debug_and_release debug_and_release_target
