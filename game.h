#ifndef GAME_H
#define GAME_H

#include "card.h"
#include "config.h"
#include "ai.h"
#include "dealer.h"

#include <QObject>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class Game : public QObject
{
    Q_OBJECT

private:
    QList<Ai*> aiPool;
    QList<Card*> cardDeck;
    Dealer *dealer = new Dealer();

    void fillAiPool( int amount );
    void fillCardDeck();
    void suffelDeck();
    void swapTwoCards(Card *c1, Card *c2 );
    void firstDeal();
    void dealCardToSomeone( Card *card, Someone *someone );

public:
    Game( QObject *parent = 0 );
    ~Game();

    void debugCardDeck();
    QList<Ai *> getAiPool() const;
    void setAiPool(const QList<Ai *> &value);
    Dealer *getDealer() const;
    void setDealer(Dealer *value);
};

#endif // GAME_H
