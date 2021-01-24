//-----------------------------------------------------
// Title: board
// Author: Deniz Dumanlı, Tunç Gürsoy
// ID: 25337236168, 64528127274
// Section: 1
// Assignment: 3
// Description: This class creates the board.
//-----------------------------------------------------
#include "board.h"
#include "box.h"
#include "game.h"
#include "stamp.h"
#include "king.h"

extern Game *game;

Board::Board(int width,int height)
{
    setUpBlack(width,height);
    setUpWhite(width,height);
}

// This method draws the boxes in the board.
void Board::drawBoxes(int x,int y,int width,int height)
{
    int SHIFT1 = width/9;
    int SHIFT2 = (height-50)/9;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
        {
            Boxe *box = new Boxe();
            box->setRECT(width/9,(height-50)/9);
            game->collection[i][j] = box;

            box->rowLoc = i;
            box->colLoc = j;
            box->setPos(x+SHIFT1*j,y+SHIFT2*i);
            if((i+j)%2==0)
                box->setOriginalColor(Qt::lightGray);
            else
                box->setOriginalColor(Qt::darkGray);
            game->addToScene(box);
        }
    }

}

//This method adds the pieces into the board.
void Board::addPiece() {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
        {

            Boxe *box = game->collection[i][j];
            if(0<i&&i < 3) {
                static int k;
                box->placePiece(black[k]);
                game->alivePiece.append(black[k]);
                game->addToScene(black[k++]);
            }
            if(i > 4&& i<7) {
                static int h;
                box->placePiece(white[h]);
                game->alivePiece.append(white[h]);
                game->addToScene(white[h++]);
            }

        }
    }
}
// This method sets pieces to white.

void Board::setUpWhite(int width,int height)
{
    Piece *piece;
    for(int i = 0; i < 16; i++) {
        piece = new Stamp("WHITE",width,height);
        white.append(piece);
    }

}

// This method sets pieces to black.
void Board::setUpBlack(int width,int height)
{
    Piece *piece;
    for(int i = 0; i < 16; i++) {
        piece = new Stamp("BLACK",width,height);
        black.append(piece);
    }
}

// This method resets the pieces.
void Board::reset() {
    int k = 0; int h = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
        {

            Boxe *box =game->collection[i][j];
            box->setHasPiece(false);
            box->setPieceColor("NONE");
            box->currentPiece = NULL;
            if(0<i&&i < 3) {

                box->placePiece(black[k]);
                black[k]->setIsPlaced(true);
                game->alivePiece.append(black[k++]);

            }
            if(i > 4&& i<7) {

                box->placePiece(white[h]);
                white[h]->setIsPlaced(true);
                game->alivePiece.append(white[h++]);

            }

        }
    }
}
