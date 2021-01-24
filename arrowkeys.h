#ifndef ARROWKEYS_H
#define ARROWKEYS_H
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>

class ArrowKeys:public QGraphicsRectItem
{
    Q_OBJECT
public:

   ArrowKeys(int buttonNum,int width,int height, QGraphicsItem * parent = NULL);

   //public methods

   //events
   void mousePressEvent(QGraphicsSceneMouseEvent *event);
   void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
   void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
   QPixmap setImage(QString location,int width= 0 ,int height= 0);
signals:
   void clicked();
private:
   QGraphicsTextItem *text;
};

#endif // ARROWKEYS_H
