#ifndef BOARD_H
#define BOARD_H
#include <QGraphicsRectItem>
#include "piece.h"

class Board
{
public:
    Board(int width,int height);
    //drawing public function
    void drawBoxes(int x, int y,int width,int height);

    void setUpWhite(int width,int height);
    void setUpBlack(int width,int height);



    void addPiece();
    void reset();
private:
    QList <Piece *> white;
    QList <Piece *> black;


};

#endif // BOARD_H
