#include "dealer.h"

QList<Dealer*> Dealer::allDealers = QList<Dealer*>();

bool Dealer::getIsCardHidden() const
{
    return isCardHidden;
}

void Dealer::setIsCardHidden(bool value)
{
    isCardHidden = value;
}

QList<Dealer *> Dealer::getAllDealers()
{
    return allDealers;
}

Dealer::Dealer()
{
    Someone::setIsDealer(true);
    allDealers.append(this);
}

Dealer::Dealer( QList<Card*> handCards ) : Someone(handCards)
{
    allDealers.append(this);
}
