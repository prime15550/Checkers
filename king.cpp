//-----------------------------------------------------
// Title: king
// Author: Deniz Dumanlı, Tunç Gürsoy
// ID: 25337236168, 64528127274
// Section: 1
// Assignment: 3
// Description: This class for main game.
//-----------------------------------------------------
#include "king.h"
#include "game.h"
#include "stamp.h"
extern Game *game;
King::King(QString team,int width,int height,QGraphicsItem *parent):Piece(team,width,height,parent)
{
    setImage(width,height);

}

// This method sets image to pieces.
void King::setImage(int width,int height)
{
    if(side == "WHITE")
        setPixmap(QPixmap(":/images/whiteKing.png"));
    else
        setPixmap(QPixmap(":/images/blackKing.png"));
}

// This method makes the movement operations.
void King::moves()
{
    location.clear();
    int row = this->getCurrentBox()->rowLoc;
    int col = this->getCurrentBox()->colLoc;
    QString team = this->getSide();
    //For up

     for(int i = row-1,j = col; i >= 0 ; i--) {
       if(game->collection[i][j]->getPieceColor() == team ) {
           break;
       }
       else
       {
           location.append(game->collection[i][j]);
           if(boxSetting(location.last()))
               break;
        }
    }

     //For Down

      for(int i = row+1,j = col; i <= 7 ; i++) {
        if(game->collection[i][j]->getPieceColor() == team ) {
            break;
        }
        else
        {
            location.append(game->collection[i][j]);
            if(boxSetting(location.last())){
                break;
            }
        }
     }

      //For left

       for(int i = row,j = col-1; j >= 0 ; j--) {
         if(game->collection[i][j]->getPieceColor() == team ) {
             break;
         }
         else
         {
             location.append(game->collection[i][j]);
             if(boxSetting(location.last()))
                break;
         }
        }
       //For Right

        for(int i = row,j = col+1; j <= 7 ; j++)
        {
              if(game->collection[i][j]->getPieceColor() == team ) {
                  break;
              }
              else
              {
                  location.append(game->collection[i][j]);
                  if(boxSetting(location.last()))
                      break;
               }

       }


}

