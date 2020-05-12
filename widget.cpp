#include "widget.h"

Widget *Widget::widget = nullptr;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    createAiSelectorButton();
    createGameButtons();

    connect( swipeSelectedAiRight, &QPushButton::clicked, this, &Widget::selectNextAi );
    connect( swipeSelectedAiLeft, &QPushButton::clicked, this, &Widget::selectPreviousAi );
    connect( hit, &QPushButton::clicked, this, &Widget::hitPressed );
    connect( stand, &QPushButton::clicked, this, &Widget::standPressed );
    connect( controllAi, &QPushButton::clicked, this, &Widget::controllAiPressed );
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
    int dealerSize = Dealer::getAllDealers()[activeTableIndex]->getHandCards().length();
    if ( dealerSize > 6 ) return;

    for( int i = 0; i < dealerSize; i++ )
        drawCard(painter, QRect( DEALER_CARD_START_POSITIONS[dealerSize-2].x()+i*(CARD_SIZE.width()+MARGIN),
                                 DEALER_CARD_START_POSITIONS[dealerSize-2].y(),
                                 CARD_SIZE.width(), CARD_SIZE.height() ),
                Dealer::getAllDealers()[activeTableIndex]->getHandCards()[i] );
    if( Dealer::getAllDealers()[activeTableIndex]->getIsCardHidden() )
        painter->drawRect(QRect( DEALER_CARD_START_POSITIONS[dealerSize-2].x()+1*(CARD_SIZE.width()+MARGIN),
                                          DEALER_CARD_START_POSITIONS[dealerSize-2].y(),
                                          CARD_SIZE.width(), CARD_SIZE.height() ));
    else
        drawCradSum( painter, Dealer::getAllDealers()[activeTableIndex], QRect( 450, 230, 100, 50) );
}

void Widget::drawPlayerHand(QPainter *painter, Ai *ai)
{
    int handSize = Ai::getAllAis()[Ai::getSelectedAiIndex()]->getHandCards().length();
    if ( handSize > 6 ) return;

    for( int i = 0; i < handSize; i++ )
        drawCard(painter, QRect( PLAYER_CARD_START_POSITIONS[handSize-2].x()+i*(CARD_SIZE.width()+MARGIN),
                                 PLAYER_CARD_START_POSITIONS[handSize-2].y(),
                                 CARD_SIZE.width(), CARD_SIZE.height() ),
                Ai::getAllAis()[Ai::getSelectedAiIndex()]->getHandCards()[i] );
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
    QPen pen = QPen(Qt::SolidLine);
    if( someone->getHandCardSum() > 21 )
        pen.setColor( Qt::red );
    else if( someone->getHandCardSum() == 21 )
        pen.setColor( Qt::green );
    else pen.setColor( Qt::black );
    painter->setPen( pen );
    painter->setFont( font );
    painter->drawText( rect, "[ " + QString::number(someone->getHandCardSum()) + " ]", QTextOption(Qt::AlignCenter) );
    pen.setColor( Qt::black );
    painter->setPen( pen );
}

void Widget::drawPlayerBalance(QPainter *painter, Ai *ai)
{
    QBrush brush = QBrush(Qt::SolidPattern);
    int aiBalance = Ai::getAllAis()[Ai::getSelectedAiIndex()]->getBalance();
    if(aiBalance > 500)
        brush.setColor( Qt::green );
    else if( aiBalance > 200 )
        brush.setColor( QColor(247, 198, 20, 255));
    else
        brush.setColor( Qt::red );
    painter->setBrush(brush);
    QFont font = QFont("Monospace", 18);
    painter->setFont(font);
    painter->drawText( QRect( 450, 360, 100, 50), "$ " + QString::number(aiBalance) + " $", QTextOption(Qt::AlignCenter) );
    painter->drawRect( QRect( 360-((280.0/1000.0)*aiBalance-280)/2, 410, (280.0/1000.0)*aiBalance, 8));
}

void Widget::createAiSelectorButton()
{
    swipeSelectedAiLeft = new QPushButton(this);
    swipeSelectedAiLeft->setGeometry( 340, 370, 18, 30 );
    swipeSelectedAiLeft->setText("<");

    swipeSelectedAiRight = new QPushButton(this);
    swipeSelectedAiRight->setGeometry( 640, 370, 18, 30 );
    swipeSelectedAiRight->setText(">");
}

void Widget::createGameButtons()
{
    hit = new QPushButton(this);
    hit->setGeometry( 570, 635, 70, 40 );
    hit->setStyleSheet("border-image:url(hit.png);");

    stand = new QPushButton(this);
    stand->setGeometry( 360, 635, 70, 40 );
    stand->setStyleSheet("border-image:url(stand.png);");

    controllAi = new QPushButton(this);
    controllAi->setGeometry( 570, 635, 70, 40 );
    controllAi->setStyleSheet("border-image:url(controll.png);");
    controllAi->setVisible( false );
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);
    drawDealerHand(painter);
    drawPlayerHand(painter, Ai::getAllAis()[Ai::getSelectedAiIndex()]);
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

void Widget::setGameButtonStatus(bool status)
{
    hit->setVisible( status );
    stand->setVisible( status );
    if( !Ai::getAllAis()[Ai::getSelectedAiIndex()]->getIsStand() ) controllAi->setVisible( !status );
    else controllAi->setVisible( status );
}

void Widget::selectNextAi()
{
    if( Ai::getSelectedAiIndex()+1 < Ai::getAllAis().length() )
        Ai::setSelectedAiIndex(Ai::getSelectedAiIndex()+1);
    else
        Ai::setSelectedAiIndex(0);
    setGameButtonStatus( !Ai::getAllAis()[Ai::getSelectedAiIndex()]->getIsStand() && Ai::getAllAis()[Ai::getSelectedAiIndex()]->getIsControlled() );
    update();
}

void Widget::selectPreviousAi()
{
    if( Ai::getSelectedAiIndex()-1 >= 0 )
        Ai::setSelectedAiIndex(Ai::getSelectedAiIndex()-1);
    else
        Ai::setSelectedAiIndex(Ai::getAllAis().length()-1);
    setGameButtonStatus( !Ai::getAllAis()[Ai::getSelectedAiIndex()]->getIsStand() && Ai::getAllAis()[Ai::getSelectedAiIndex()]->getIsControlled() );
    update();
}
