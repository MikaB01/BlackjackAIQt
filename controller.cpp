#include "controller.h"

Controller *Controller::controller = nullptr;

Controller::Controller(QObject *parent)
{
    w = Widget::get();
    g = new Game();

    w->setFixedSize( 1000, 700 );
    w->show();

    connect( w, &Widget::hitPressed, this, &Controller::hitCard );
    connect( w, &Widget::standPressed, this, &Controller::stand );
    connect( w, &Widget::controllAiPressed, this, &Controller::controllAi );
}

Controller *Controller::get()
{
    if( !controller )
        controller = new Controller();
    return controller;
}

void Controller::hitCard()
{
    g->dealCardToSomeone( Ai::getAllAis()[Ai::getSelectedAiIndex()] );
    w->update();
}

void Controller::stand()
{
    Ai::getAllAis()[Ai::getSelectedAiIndex()]->setIsStand( true );
    w->setGameButtonStatus( false );
    w->update();
}

void Controller::controllAi()
{
    Ai::getAllAis()[Ai::getSelectedAiIndex()]->setIsControlled( true );
    w->setGameButtonStatus( true );
    w->update();
}
