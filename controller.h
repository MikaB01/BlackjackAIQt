#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QtCore>

#include "widget.h"
#include "game.h"

class Controller : public QObject
{
private:
    static Controller *controller;
    Game   *g;
    Widget *w;
    Controller( QObject *parent = 0 );

public:
    static Controller *get();

public slots:
    void hitCard();
    void stand();
    void controllAi();
};

#endif // CONTROLLER_H
