#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>
#include <iostream>

#include "config.h"
#include "game.h"

class Widget : public QWidget
{
    Q_OBJECT

private:
    static Widget *widget;
    Widget(QWidget *parent = 0);
    Game   *g;
    void drawCard( QPainter *painter , QRect rect, Card *card );
    void drawDealerHand( QPainter *painter );
    void drawPlayerHand( QPainter *painter, Ai *ai );
    void drawCardSymbole(QPainter *painter , QRect rect, Card *card);
    void drawCradSum( QPainter *painter, Someone *someone, QRect rect );
    void drawPlayerBalance( QPainter *painter, Ai *ai );

protected:
    void paintEvent( QPaintEvent *event );

public:
    ~Widget();
    static Widget *get();
};

#endif // WIDGET_H