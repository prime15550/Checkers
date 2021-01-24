#include "arrowkeys.h"
#include <QPainter>
ArrowKeys::ArrowKeys(int buttonNum,int width,int height, QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    setRect(0,0,width,height);
    QPainter brush;

    QPixmap temp ;
    //draw Text
    if(buttonNum==0)
    {

        temp = setImage(":/Images/upButton.png",width,height);
    }else if(buttonNum==1)
    {
         temp = setImage(":/Images/leftButton.png",width,height);

    }else
    {
         temp = setImage(":/Images/rightButton.png",width,height);

    }
    brush.drawPixmap(100,0,temp);

}void ArrowKeys::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event)
    emit clicked();

}
QPixmap ArrowKeys::setImage(QString location,int width,int height)
{

   return (QPixmap(location).scaled(((double)width/1400.0)*100,((double)height/900.0)*100,Qt::KeepAspectRatio,Qt::SmoothTransformation));
}

void ArrowKeys::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    //change color
    if(event){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
    }
}
void ArrowKeys::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    //change color
    if(event){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);
    }
}
