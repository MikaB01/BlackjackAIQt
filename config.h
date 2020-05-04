#ifndef CONFIG_H
#define CONFIG_H

#include <QtCore>

enum cardSymbole {
    HEARTS = 1,
    SPADES = 2,
    DIAMONDS = 3,
    CLUBS = 4
};

const QSize CARD_SIZE( 120, 180 );

const int MARGIN = 40;

const QList<cardSymbole> CARD_SYMBOLE_STRING_LIST = QList<cardSymbole>() << HEARTS << SPADES << DIAMONDS << CLUBS;
const QList<QString> UTF8SYMBOLES = QList<QString>() << "\u2665" << "\u2660" << "\u2666" << "\u2663" ;

const QList<QString> CARD_NAME_LIST = QList<QString>() << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9" << "10" << "A" << "B" << "D" << "K";

const QList<QPoint> DEALER_CARD_START_POSITIONS = QList<QPoint>() << QPoint( 360, MARGIN ) <<
                                                                     QPoint( 280, MARGIN ) <<
                                                                     QPoint( 200, MARGIN ) <<
                                                                     QPoint( 120, MARGIN ) <<
                                                                     QPoint( 40, MARGIN );

const QList<QPoint> PLAYER_CARD_START_POSITIONS = QList<QPoint>() << QPoint( 360, MARGIN+400 ) <<
                                                                     QPoint( 280, MARGIN+400 ) <<
                                                                     QPoint( 200, MARGIN+400 ) <<
                                                                     QPoint( 120, MARGIN+400 ) <<
                                                                     QPoint( 40, MARGIN+400 );


#endif // CONFIG_H
