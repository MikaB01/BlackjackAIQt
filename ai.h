#ifndef AI_H
#define AI_H

#include <QtCore>

#include "card.h"
#include "someone.h"

class Ai : public Someone
{
private:
    int balance = 1000;
    bool isControlled = false;
    static QList<Ai*> allAis;
    static int selectedAiIndex;

public:
    Ai();
    Ai( bool isControlled );
    Ai( QList<Card*> handCards);
    Ai( int balance, QList<Card*> handCards );
    int getBalance() const;
    void setBalance(int value);
    bool getIsControlled() const;
    void setIsControlled(bool value);

    static QList<Ai *> getAllAis();
    static int getSelectedAiIndex();
    static void setSelectedAiIndex(int index);
};

#endif // AI_H
