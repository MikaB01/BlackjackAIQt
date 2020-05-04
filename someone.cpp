#include "someone.h"

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

Someone::Someone()
{

}

Someone::Someone(QList<Card *> handCards)
{
    this->handCards = handCards;
}

void Someone::addHandCard(Card *c)
{
    handCards << c;
}

void Someone::debugHandCrads()
{
    qDebug() << "---Debug-HandCards--- (" << getHandCardSum() << ")" ;
    for( int i = 0; i < handCards.length(); i++ ) {
        qDebug() << handCards[i]->getName() << " | " << handCards[i]->getValue() << " | " << handCards[i]->getSymbole();
    }
}
