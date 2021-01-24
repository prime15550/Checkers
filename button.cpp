//-----------------------------------------------------
// Title: button
// Author: Deniz Dumanlı, Tunç Gürsoy
// ID: 25337236168, 64528127274
// Section: 1
// Assignment: 3
// Description: This class is to make buttons.
//-----------------------------------------------------
#include "button.h"
#include "popup.h"
#include <QGraphicsTextItem>
#include <QBrush>
#include <help.h>
#include <file.h>

// Here it aligns the buttons.
Button::Button(QString name,int width,int height, QGraphicsItem *parent):QGraphicsRectItem(parent)
{

    setRect(0,0,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);

    //draw Text
    text = new QGraphicsTextItem(name,this);
    if(name=="Game")
    {
        type=0;
    }else if(name=="Undo")
    {
        type = 1;
    }else if(name =="Help")
    {
        type = 2;
    }else if(name == "File")
    {
        type =3 ;
    }else if(name=="New-Game")
    {
        type = 4 ;
    }
    else{
        type = 999;
    }
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);
    text->setDefaultTextColor(Qt::black);

    //Allow responding to hover
    setAcceptHoverEvents(true);
}

// This method makes the buttons clickable.
void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(this->type==0){
    Popup dialog ;
    dialog.setModal(true);
    dialog.exec();
    }
    if(this->type==1)
    {
        game->undo();
    }
    if(this->type==2)
    {
        help dialog ;
        dialog.setModal(true);
        dialog.exec();
    }
    if(this->type==3)
    {
        File dialog ;
        dialog.setModal(true);
        dialog.exec();
    }
    if(this->type==4)
    {

        game->gameOver();
    }
}

// This method changes the colors of the buttons when we are on them.
void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    //change color
    if(event){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
    }
}

// This method resets the color when we are not on the button.
void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    //change color
    if(event){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);
    }
}
