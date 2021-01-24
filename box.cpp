//-----------------------------------------------------
// Title: box
// Author: Deniz Dumanlı, Tunç Gürsoy
// ID: 25337236168, 64528127274
// Section: 1
// Assignment: 3
// Description: This class is for moving pieces.
//-----------------------------------------------------
#include "box.h"
#include "game.h"
#include "king.h"
#include <QDebug>

extern Game *game;

Boxe::Boxe(QGraphicsItem *parent):QGraphicsRectItem(parent)
{

}

Boxe::~Boxe()
{
    delete this;
}

// This method sets rectangles.
void Boxe::setRECT(int width, int height)
{
    setRect(0,0,width,height);
    brush.setStyle(Qt::SolidPattern);
    setZValue(-1);
    setHasPiece(false);
    setPieceColor("NONE");
    currentPiece = NULL;
}
// This method makes the pieces clickable.
void Boxe::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

        if(currentPiece == game->pieceToMove && currentPiece){

            currentPiece->mousePressEvent(event);
            return;
        }

        //if selected
        if(game->pieceToMove){
            //if same team
            if(this->getPieceColor() == game->pieceToMove->getSide())
                return;
            //removing the eaten piece
            QList <Boxe *> movLoc = game->pieceToMove->moveLocation();
            //TO make sure the selected box is in move zone
            int check = 0;
            for(size_t i = 0, n = movLoc.size(); i < n;i++) {
                if(movLoc[i] == this) {
                    check++;

                }
            }

            if(check == 0)
                return;

             game->pieceToMove->decolor();

            if(this->getHasPiece()){
                this->currentPiece->setIsPlaced(false);
                this->currentPiece->setCurrentBox(NULL);

            }
            //changing the new stat and resetting the previous left region
            game->assignpast(game->pieceToMove->getCurrentBox());
            game->pieceToMove->getCurrentBox()->setHasPiece(false);
            game->pieceToMove->getCurrentBox()->currentPiece = NULL;
            game->pieceToMove->getCurrentBox()->resetOriginalColor();
            placePiece(game->pieceToMove);
            game->isundoit = false;
            game->assignpast1(this);
            game->pieceToMove = NULL;
            //changing turn
            game->changeTurn();
            checkForCheck();
        }
        //Selecting couterpart of the chessPiece
        else if(this->getHasPiece())
        {
            this->currentPiece->mousePressEvent(event);
        }
}

// This method sets a color for moving place for chosen piece.
void Boxe::setColor(QColor color)
{
    brush.setColor(color);
    setBrush(color);
}

// This method shows the placed piece.
void Boxe::placePiece(Piece *piece)
{

    piece->setPos(x()+boundingRect().width()/2- piece->pixmap().width()/2  ,y()+boundingRect().height()/2-piece->pixmap().width()/2);


    piece->setCurrentBox(this);
    setHasPiece(true,piece);
    currentPiece = piece;


}

// This method resets the places original color.
void Boxe::resetOriginalColor()
{
    setColor(originalColor);
}

// This method is for to set original color.
void Boxe::setOriginalColor(QColor value)
{
    originalColor = value;
    setColor(originalColor);
}

// This method is to check is there piece or not.
bool Boxe::getHasPiece()
{
    return hasPiece;
}

// This method checks is there piece, and colorsda piece's places according to that.
void Boxe::setHasPiece(bool value, Piece *piece)
{
    hasPiece = value;
    if(value)
        setPieceColor(piece->getSide());
    else
        setPieceColor("NONE");
}

// This method checks is there any check in the game.
void Boxe::checkForCheck()
{
    int c = 0;
    QList <Piece *> pList = game->alivePiece;
    for(size_t i = 0,n=pList.size(); i < n; i++ ) {

        King * p = dynamic_cast<King *> (pList[i]);
        if(p){
            continue;
        }
        pList[i]->moves();
        pList[i]->decolor();
        QList <Boxe *> bList = pList[i]->moveLocation();
        for(size_t j = 0,n = bList.size(); j < n; j ++) {
            King * p = dynamic_cast<King *> (bList[j]->currentPiece);
            if(p) {
                if(p->getSide() == pList[i]->getSide())
                    continue;
                bList[j]->setColor(Qt::blue);
                pList[i]->getCurrentBox()->setColor(Qt::darkRed);
                if(!game->check->isVisible())
                    game->check->setVisible(true);
                else{
                    bList[j]->resetOriginalColor();
                    pList[i]->getCurrentBox()->resetOriginalColor();
                    game->gameOver();
                }
                c++;

            }
        }


    }
    if(!c){
        game->check->setVisible(false);
        for(size_t i = 0,n=pList.size(); i < n; i++ )
            pList[i]->getCurrentBox()->resetOriginalColor();
    }
}

// This method gets the piece color.
QString Boxe::getPieceColor()
{
    return PieceColor;
}

// This method sets piece color.
void Boxe::setPieceColor(QString value)
{
    PieceColor = value;
}
