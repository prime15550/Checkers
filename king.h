#ifndef KING_H
#define KING_H

#include "piece.h"
class King:public Piece
{
public:
    King(QString team,int width,int height,QGraphicsItem *parent = 0);
    void setImage(int width,int height);
    void moves();
};

#endif // KING_H
