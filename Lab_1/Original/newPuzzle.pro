#-------------------------------------------------
#
# Project created by QtCreator 2019-05-30T15:10:04
#
#-------------------------------------------------

QT       += core gui
QT += testlib


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = newPuzzle
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
        authorization.cpp \
    menu1.cpp \
    forpleasure.cpp \
    puzzle.cpp \
    clickablelabel.cpp \
    singleton.cpp \
    levels.cpp \
    sublevels.cpp \
    settings.cpp \
    end.cpp

HEADERS += \
        authorization.h \
    menu1.h \
    forpleasure.h \
    authorization.h \
    puzzle.h \
    clickablelabel.h \
    singleton.h \
    levels.h \
    sublevels.h \
    settings.h \
    end.h \
    testing.h \
    sortfactory.h

FORMS += \
        authorization.ui \
    menu1.ui \
    forpleasure.ui \
    puzzle.ui \
    levels.ui \
    sublevels.ui \
    settings.ui \
    end.ui

DISTFILES += \
    1/1.jpg \
    1/2.jpg \
    2/3.jpg \
    2/31.jpg \
    2/32.jpg \
    2/4.jpg \
    2/41.jpg \
    2/42.jpg \
    3/5.jpg \
    3/51.jpg \
    3/52.jpg \
    3/53.jpg \
    3/6.jpg \
    3/61.jpg \
    3/62.jpg \
    3/63.jpg \
    4/7.jpg \
    4/71.jpg \
    4/72.jpg \
    4/73.jpg \
    4/74.jpg \
    4/75.jpg \
    4/8.jpg \
    4/81.jpg \
    4/82.jpg \
    4/83.jpg \
    4/84.jpg \
    4/85.jpg \
    5/9.png \
    back.jpg \
    star.png

RESOURCES += \
    levels.qrc



