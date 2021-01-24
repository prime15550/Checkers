#ifndef STAMP_H
#define STAMP_H

#include "piece.h"
class Stamp:public Piece
{
public:
    Stamp(QString team,int width= 0 ,int height= 0,QGraphicsItem *parent = 0);
    void setImage(int width= 0 ,int height= 0);

    void moves();

 private:
};

#endif // STAMP_H
