#include "controller.h"

Controller *Controller::controller = nullptr;

Controller::Controller(QObject *parent)
{
    w = Widget::get();
    //g = new Game();

    w->setFixedSize( 1000, 700 );
    w->show();


}

Controller *Controller::get()
{
    if( !controller )
        controller = new Controller();
    return controller;
}
