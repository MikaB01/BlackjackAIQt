#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QtCore>

#include "widget.h"
#include "game.h"

class Controller : public QObject
{
private:
    static Controller *controller;
    Widget *w;
    //Game   *g;
    Controller( QObject *parent = 0 );

public:
    static Controller *get();
};

#endif // CONTROLLER_H
