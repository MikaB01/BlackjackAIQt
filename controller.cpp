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
}

Controller *Controller::get()
{
    if( !controller )
        controller = new Controller();
    return controller;
}

void Controller::hitCard()
{
    g->dealCardToSomeone( g->getAiPool()[w->selectedAiIndex] );
    w->update();
}

void Controller::stand()
{
    g->getAiPool()[w->selectedAiIndex]->setIsStand( true );
    w->setGameButtonStatus( false );
    w->update();
}
