#-------------------------------------------------
#
# Project created by QtCreator 2016-04-07T13:54:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = arkanoid
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    cube.cpp \
    game.cpp \
    ball.cpp \
    racket.cpp \
    score.cpp \
    lives.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    cube.h \
    game.h \
    ball.h \
    racket.h \
    score.h \
    lives.h

FORMS    += mainwindow.ui \
    dialog.ui

RESOURCES += \
    img.qrc

DISTFILES +=
