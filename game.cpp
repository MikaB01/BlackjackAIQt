#include "game.h"

QList<Ai *> Game::getAiPool() const
{
    return aiPool;
}

void Game::setAiPool(const QList<Ai *> &value)
{
    aiPool = value;
}

Dealer *Game::getDealer() const
{
    return dealer;
}

void Game::setDealer(Dealer *value)
{
    dealer = value;
}

void Game::fillCardDeck()
{
    for( int i = 0; i < 10; i++ )
        for( int j = 0; j < 4; j++ )
            cardDeck << new Card( CARD_NAME_LIST[i], i+2, CARD_SYMBOLE_STRING_LIST[j] );

    for( int i = 0; i < 3; i++ )
        for( int j = 0; j < 4; j++ )
            cardDeck << new Card( CARD_NAME_LIST[i+10], 10, CARD_SYMBOLE_STRING_LIST[j] );
}

void Game::suffelDeck()
{
    for( int i = 0; i < 99999; i++ )
        swapTwoCards( cardDeck[rand() % 52], cardDeck[rand() % 52] );
    qDebug() << "Deck suffeled!";
}

void Game::swapTwoCards(Card *c1, Card *c2)
{
    Card *tmp = c1;
    cardDeck[cardDeck.indexOf(c1)] = c2;
    cardDeck[cardDeck.indexOf(c2)] = tmp;
}

void Game::firstDeal()
{
    /*foreach ( Ai *a, aiPool ){
        a->addHandCard( cardDeck.pop_back() );
    }*/

    foreach ( Ai *a, aiPool ){
        for( int i = 0; i < 2; i++ ) {
            a->addHandCard( cardDeck.last() );
            cardDeck.removeAt( cardDeck.indexOf(cardDeck.last()) );
        }
    }

    for( int i = 0; i < 2; i++ ) {
        dealer->addHandCard( cardDeck.last() );
        cardDeck.removeAt( cardDeck.indexOf(cardDeck.last()) );
    }
}

void Game::debugCardDeck()
{
    qDebug() << "---Debug-CardDeck--- (" << cardDeck.length() << ")";
    for( int i = 0; i < cardDeck.length(); i++ ) {
        qDebug() << cardDeck[i]->getName() << " | " <<cardDeck[i]->getValue() << " | " << cardDeck[i]->getSymbole();
    }
}

Game::Game(QObject *parent)
{
    srand (time(NULL));

    aiPool << new Ai() << new Ai();

    fillCardDeck();
    debugCardDeck();
    suffelDeck();
    debugCardDeck();
    firstDeal();
    debugCardDeck();
    foreach ( Ai *a, aiPool ){
        a->debugHandCrads();
    }
    dealer->debugHandCrads();
}

Game::~Game()
{

}
