#ifndef PIECE_H
#define PIECE_H

#include "box.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class Boxe;
class Piece:public QGraphicsPixmapItem
{
public:
    Piece(QString team = "",int width= 0 ,int height= 0,QGraphicsItem *parent = 0);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setCurrentBox(Boxe *box);

    Boxe *getCurrentBox() ;

    QString getSide() ;
    void setSide( QString value);
    virtual void setImage(int width,int height) = 0;

    bool getIsPlaced() ;
    void setIsPlaced(bool value);

    QList <Boxe *> moveLocation();
    virtual void moves() = 0;
    void decolor();




    bool boxSetting(Boxe *box);
protected:
    Boxe *currentBox;
    QString side;
    bool isPlaced;
    QList <Boxe *> location;

};

#endif // PIECE_H
