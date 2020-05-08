#ifndef AI_H
#define AI_H

#include <QtCore>

#include "card.h"
#include "someone.h"

class Ai : public Someone
{
private:
    int balance = 1000;
    static QList<Ai*> allAis;

public:
    Ai();
    Ai( QList<Card*> handCards);
    Ai( int balance, QList<Card*> handCards );
    int getBalance() const;
    void setBalance(int value);

    static QList<Ai *> getAllAis();
};

#endif // AI_H
