#-------------------------------------------------
#
# Project created by QtCreator 2020-05-02T10:44:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = blackjackBetAI
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    controller.cpp \
    game.cpp \
    card.cpp \
    ai.cpp \
    someone.cpp \
    dealer.cpp

HEADERS  += widget.h \
    controller.h \
    game.h \
    card.h \
    config.h \
    ai.h \
    someone.h \
    dealer.h
