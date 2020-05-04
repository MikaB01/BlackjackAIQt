#ifndef SOMEONE_H
#define SOMEONE_H

#include <QtCore>

#include "card.h"

class Someone
{
private:

protected:
    QList<Card*> handCards;
    bool isDealer = false;
    static QList<Someone*> allSomeone;

public:
    Someone();
    Someone( bool *isDealer );
    Someone( QList<Card*> handCards );

    QList<Card *> getHandCards() const;
    void addHandCard( Card *c );
    void debugHandCrads();
    void setHandCards( const QList<Card *> &value );
    int getHandCardSum();

    static QList<Someone *> getAllSomeone();
    static void debugSomeone(Someone *someone );
    static void debugAllSomeones();
    bool getIsDealer() const;
    void setIsDealer( bool isDealer );
};

#endif // SOMEONE_H
