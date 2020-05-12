#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>
#include <iostream>

#include "config.h"
#include "game.h"
#include "ai.h"

class Widget : public QWidget
{
    Q_OBJECT

private:
    static Widget *widget;
    Widget(QWidget *parent = 0);

    QPushButton *swipeSelectedAiRight;
    QPushButton *swipeSelectedAiLeft;
    QPushButton *hit;
    QPushButton *stand;

    void drawCard( QPainter *painter , QRect rect, Card *card );
    void drawDealerHand( QPainter *painter );
    void drawPlayerHand( QPainter *painter, Ai *ai );
    void drawCardSymbole(QPainter *painter , QRect rect, Card *card);
    void drawCradSum( QPainter *painter, Someone *someone, QRect rect );
    void drawPlayerBalance( QPainter *painter, Ai *ai );
    void createAiSelectorButton();
    void createGameButtons();

protected:
    void paintEvent( QPaintEvent *event );

public:
    ~Widget();
    static Widget *get();

    int activeTableIndex = 0;

    void setGameButtonStatus( bool status );

public slots:
    void selectNextAi();
    void selectPreviousAi();

signals:
    void hitPressed();
    void standPressed();
};

#endif // WIDGET_H
