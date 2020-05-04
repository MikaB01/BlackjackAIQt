#include "dealer.h"

bool Dealer::getIsCardHidden() const
{
    return isCardHidden;
}

void Dealer::setIsCardHidden(bool value)
{
    isCardHidden = value;
}

Dealer::Dealer()
{

}

Dealer::Dealer( QList<Card*> handCards ) : Someone(handCards)
{

}