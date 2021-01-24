#ifndef BUTTON_H
#define BUTTON_H
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include <Game.h>
extern Game *game;
class Button:public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:

   Button(QString name,int width,int height, QGraphicsItem * parent = NULL);

   //public methods
    int type ;
   //events
   void mousePressEvent(QGraphicsSceneMouseEvent *event);
   void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
   void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
signals:
   void clicked();
private:
   QGraphicsTextItem *text;
};

#endif // BUTTON_H
