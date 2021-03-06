#include "ai.h"

QList<Ai*> Ai::allAis = QList<Ai*>();
int Ai::selectedAiIndex = 0;

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

int Ai::getSelectedAiIndex()
{
    return selectedAiIndex;
}

void Ai::setSelectedAiIndex(int index)
{
    selectedAiIndex = index;
}

bool Ai::getIsControlled() const
{
    return isControlled;
}

void Ai::setIsControlled(bool value)
{
    isControlled = value;
}

Ai::Ai()
{
    allAis.append( this );
}

Ai::Ai(bool isControlled)
{
    this->isControlled = isControlled;
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
