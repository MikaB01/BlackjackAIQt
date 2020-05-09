#include "someone.h"

QList<Someone*> Someone::allSomeone = QList<Someone*>();

QList<Card *> Someone::getHandCards() const
{
    return handCards;
}

void Someone::setHandCards(const QList<Card *> &value)
{
    handCards = value;
}

int Someone::getHandCardSum()
{
    int sum = 0;
    for( int i = 0; i < handCards.length(); i++ )
        sum += handCards[i]->getValue();
    return sum;
}

QList<Someone *> Someone::getAllSomeone()
{
    return allSomeone;
}

void Someone::debugSomeone(Someone *someone)
{
    if( someone->getIsDealer() )
        qDebug() << "----Dealer----";
    else {
        qDebug() << "----  AI  ----";
        qDebug() << "| Balance:   |";
    }
    someone->debugHandCrads();

}

void Someone::debugAllSomeones()
{
    foreach( Someone *someone, Someone::allSomeone )
        debugSomeone( someone );
}

bool Someone::getIsDealer() const
{
    return isDealer;
}

void Someone::setIsDealer(bool isDealer)
{
    this->isDealer = isDealer;
}

bool Someone::getIsStand() const
{
    return isStand;
}

void Someone::setIsStand(bool value)
{
    isStand = value;
}

Someone::Someone()
{
    allSomeone.append( this );
}

Someone::Someone(bool *isDealer)
{
    this->isDealer = isDealer;
}

Someone::Someone(QList<Card *> handCards)
{
    this->handCards = handCards;
    allSomeone.append( this );
}

void Someone::addHandCard(Card *c)
{
    handCards << c;
}

void Someone::debugHandCrads()
{
    qDebug() << "---Debug-HandCards--- (" << getHandCardSum() << ")" ;
    for( int i = 0; i < handCards.length(); i++ ) {
        qDebug() << "| " << handCards[i]->getName() << " | " << handCards[i]->getValue() << " | " << handCards[i]->getSymbole() << " |";
    }
}
