#ifndef SOMEONE_H
#define SOMEONE_H

#include <QtCore>

#include "card.h"

class Someone
{
private:

protected:
    QList<Card*> handCards;
public:
    Someone();
    Someone(QList<Card*> handCards);
    QList<Card *> getHandCards() const;
    void addHandCard( Card *c );
    void debugHandCrads();
    void setHandCards(const QList<Card *> &value);
    int getHandCardSum();
};

#endif // SOMEONE_H
