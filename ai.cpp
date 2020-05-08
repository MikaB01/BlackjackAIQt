#include "ai.h"

QList<Ai*> Ai::allAis = QList<Ai*>();

int Ai::getBalance() const
{
    return balance;
}

void Ai::setBalance(int value)
{
    balance = value;
}

QList<Ai *> Ai::getAllAis()
{
    return allAis;
}

Ai::Ai()
{
    allAis.append( this );
}

Ai::Ai(QList<Card*> handCards) : Someone(handCards)
{
    allAis.append( this );
}

Ai::Ai(int balance, QList<Card*> handCards) : Someone(handCards)
{
    this->balance = balance;
    allAis.append( this );
}
