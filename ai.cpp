#include "ai.h"

int Ai::getBalance() const
{
    return balance;
}

void Ai::setBalance(int value)
{
    balance = value;
}

Ai::Ai()
{

}

Ai::Ai(QList<Card*> handCards) : Someone(handCards)
{

}

Ai::Ai(int balance, QList<Card*> handCards) : Someone(handCards)
{
    this->balance = balance;
}
