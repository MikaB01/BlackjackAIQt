#include "game.h"

Dealer *Game::getDealer() const
{
    return dealer;
}

void Game::setDealer(Dealer *value)
{
    dealer = value;
}

void Game::dealCardToSomeone(Someone *someone)
{
    someone->addHandCard( cardDeck.last() );
    cardDeck.removeAt( cardDeck.indexOf( cardDeck.last() ) );
}

void Game::fillAiPool(int amount)
{
    for(int i = 0; i < amount; i++)
        new Ai();
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
    foreach ( Someone *someone, Someone::getAllSomeone() )
        for( int i = 0; i < 2; i++ )
            dealCardToSomeone( cardDeck.last(), someone );
}

void Game::dealCardToSomeone(Card *card, Someone *someone)
{
    someone->addHandCard( card );
    cardDeck.removeAt( cardDeck.indexOf( card ) );
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

    fillAiPool( 4 );
    fillCardDeck();
    debugCardDeck();

    suffelDeck();
    debugCardDeck();
    firstDeal();
    debugCardDeck();
    Someone::debugAllSomeones();

    if( Ai::getAllAis()[Ai::getSelectedAiIndex()+1]->getIsStand() )
        qDebug() << "Stand!";
}

Game::~Game()
{

}
