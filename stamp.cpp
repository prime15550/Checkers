//-----------------------------------------------------
// Title: stamp
// Author: Deniz Dumanlı, Tunç Gürsoy
// ID: 25337236168, 64528127274
// Section: 1
// Assignment: 3
// Description: This class gives a image to the pieces and makes their moves.
//-----------------------------------------------------
#include "stamp.h"
#include "game.h"
#include <QDebug>
#include <typeinfo>
#include "king.h"
extern Game * game;
Stamp::Stamp(QString team,int width ,int height,QGraphicsItem *parent):Piece(team,width,height,parent)
{
setImage(width,height);
}

// This method sets a image for pieces.
void Stamp::setImage(int width ,int height)
{
    if(side == "WHITE")
        setPixmap(QPixmap(":/Images/whiteMan.png").scaled(((double)width/1400.0)*100,((double)height/900.0)*100,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    else
        setPixmap(QPixmap(":/Images/blackMan.png").scaled(((double)width/1400.0)*100,((double)height/900.0)*100,Qt::KeepAspectRatio,Qt::SmoothTransformation));
}


// This method is for move the pieces.
void Stamp::moves()
{
    location.clear();

    int row = this->getCurrentBox()->rowLoc;

    int col = this->getCurrentBox()->colLoc;
    if(this->getSide() == "WHITE")  {

        if(row>0&&col<8  && (!game->collection[row-1][col]->getHasPiece())) {
            location.append(game->collection[row-1][col]);
            boxSetting(location.last());
        }
        if(row>0&&col<8  && (!game->collection[row][col+1]->getHasPiece())) {
            location.append(game->collection[row][col+1]);
            boxSetting(location.last());
        }
        if(row>0&&col<8  && (!game->collection[row][col-1]->getHasPiece())) {
            location.append(game->collection[row][col-1]);
            boxSetting(location.last());
        }

    }
    else{

        if(row<7&&col<8 && (!game->collection[row+1][col]->getHasPiece())) {
            location.append(game->collection[row+1][col]);
            boxSetting(location.last());
        }
        if(row<7 &&col<8&& (!game->collection[row][col+1]->getHasPiece())) {
            location.append(game->collection[row][col+1]);
            boxSetting(location.last());
        }
        if(row<7&&col<8 && (!game->collection[row][col-1]->getHasPiece())) {
            location.append(game->collection[row][col-1]);
            boxSetting(location.last());
        }

    }

}
