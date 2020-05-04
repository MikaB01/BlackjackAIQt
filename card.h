#ifndef CARD_H
#define CARD_H

#include <QtCore>

#include "config.h"

class Card
{
private:
    QString name;
    int value;
    cardSymbole symbole;

public:
    Card();
    Card( QString name, int value, cardSymbole symbole );
    int getValue() const;
    void setValue(int value);
    cardSymbole getSymbole() const;
    void setSymbole(const cardSymbole &value);
    QString getName() const;
    void setName(const QString &value);
};

#endif // CARD_H
