#include "widget.h"

Widget *Widget::widget = nullptr;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    g = new Game();
}

void Widget::drawCard(QPainter *painter, QRect rect, Card *card)
{
    QBrush brush = QBrush(Qt::SolidPattern);
    QFont font = QFont("Monospace", 18);
    brush.setColor(QColor(255, 252, 227, 255));
    painter->setBrush(brush);
    painter->setFont(font);
    painter->drawRect( rect );
    painter->drawText( QRect( rect.x(), rect.y()+8, 40, 20 ), card->getName(), QTextOption(Qt::AlignCenter) );
    painter->rotate(180);
    painter->drawText(QRect( -rect.x()-151, -rect.y()-212, 100, 100 ), card->getName(), QTextOption(Qt::AlignCenter) );
    painter->rotate(-180);
    drawCardSymbole( painter, rect, card );
}

void Widget::drawDealerHand(QPainter *painter)
{
    int dealerSize = g->getDealer()->getHandCards().length();
    if ( dealerSize > 6 ) return;

    for( int i = 0; i < dealerSize; i++ )
        drawCard(painter, QRect( DEALER_CARD_START_POSITIONS[dealerSize-2].x()+i*(CARD_SIZE.width()+MARGIN),
                                 DEALER_CARD_START_POSITIONS[dealerSize-2].y(),
                                 CARD_SIZE.width(), CARD_SIZE.height() ),
                g->getDealer()->getHandCards()[i] );
    if( g->getDealer()->getIsCardHidden() )
        painter->drawRect(QRect( DEALER_CARD_START_POSITIONS[dealerSize-2].x()+1*(CARD_SIZE.width()+MARGIN),
                                          DEALER_CARD_START_POSITIONS[dealerSize-2].y(),
                                          CARD_SIZE.width(), CARD_SIZE.height() ));
    else
        drawCradSum( painter, g->getDealer(), QRect( 450, 230, 100, 50) );
}

void Widget::drawPlayerHand(QPainter *painter, Ai *ai)
{
    int handSize = ai->getHandCards().length();
    if ( handSize > 6 ) return;

    for( int i = 0; i < handSize; i++ )
        drawCard(painter, QRect( PLAYER_CARD_START_POSITIONS[handSize-2].x()+i*(CARD_SIZE.width()+MARGIN),
                                 PLAYER_CARD_START_POSITIONS[handSize-2].y(),
                                 CARD_SIZE.width(), CARD_SIZE.height() ),
                ai->getHandCards()[i] );
    drawCradSum( painter, ai, QRect( 450, 630, 100, 50) );
    drawPlayerBalance( painter, ai );
}

void Widget::drawCardSymbole(QPainter *painter, QRect rect, Card *card )
{
    QFont font = QFont("Monospace", 30);
    painter->setFont(font);
    painter->drawText( rect, UTF8SYMBOLES[CARD_SYMBOLE_STRING_LIST.indexOf(card->getSymbole())], QTextOption(Qt::AlignCenter) );
}

void Widget::drawCradSum(QPainter *painter, Someone *someone, QRect rect )
{
    QFont font = QFont("Monospace", 24);
    painter->setFont(font);
    painter->drawText( rect, "[ " + QString::number(someone->getHandCardSum()) + " ]", QTextOption(Qt::AlignCenter) );
}

void Widget::drawPlayerBalance(QPainter *painter, Ai *ai)
{
    QBrush brush = QBrush(Qt::SolidPattern);
    if(ai->getBalance() > 500)
        brush.setColor( Qt::green );
    else if( ai->getBalance() > 200 )
        brush.setColor( QColor(247, 198, 20, 255));
    else
        brush.setColor( Qt::red );
    painter->setBrush(brush);
    QFont font = QFont("Monospace", 18);
    painter->setFont(font);
    painter->drawText( QRect( 450, 360, 100, 50), "$ " + QString::number(ai->getBalance()) + " $", QTextOption(Qt::AlignCenter) );
    painter->drawRect( QRect( 360-((280.0/1000.0)*ai->getBalance()-280)/2, 410, (280.0/1000.0)*ai->getBalance(), 8));
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);
    drawDealerHand(painter);
    drawPlayerHand(painter, g->getAiPool()[0]);
}

Widget::~Widget()
{

}

Widget *Widget::get()
{
    if( !widget )
        widget = new Widget();
    return widget;
}
