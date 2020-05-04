#include "card.h"

int Card::getValue() const
{
    return value;
}

void Card::setValue(int value)
{
    value = value;
}

cardSymbole Card::getSymbole() const
{
    return symbole;
}

void Card::setSymbole(const cardSymbole &value)
{
    symbole = value;
}

QString Card::getName() const
{
    return name;
}

void Card::setName(const QString &value)
{
    name = value;
}

Card::Card()
{

}

Card::Card(QString name, int value, cardSymbole symbole)
{
    this->name = name;
    this->value = value;
    this->symbole = symbole;
}
