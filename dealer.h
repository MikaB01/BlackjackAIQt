#ifndef DEALER_H
#define DEALER_H

#include <QtCore>

#include "card.h"
#include "someone.h"

class Dealer : public Someone
{
private:
    bool isCardHidden = true;
    static QList<Dealer*> allDealers;

public:
    Dealer();
    Dealer( QList<Card*> handCards );
    bool getIsCardHidden() const;
    void setIsCardHidden(bool value);
    static QList<Dealer*> getAllDealers();
};

#endif // DEALER_H
