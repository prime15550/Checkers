#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <board.h>

#include "piece.h"

class Game:public QGraphicsView
{
    Q_OBJECT
public:
    //Constructors
    Game(QWidget *parent = 0);

    //public Methods
    void drawBoard();
    void displayDeadWhite();
    void displayDeadBlack();
    void placeInDeadPlace(Piece *piece);

    //Scene Related
    void addToScene(QGraphicsItem *item);
    void removeFromScene(QGraphicsItem *item);

    //getters/setters
    Piece *pieceToMove;

    QString getTurn() ;
    void setTurn( QString value);
    void changeTurn();

    Boxe *collection[8][8];
    Boxe *past;
    Boxe *past1;
    QGraphicsTextItem *check;
    QList <Piece *> alivePiece;
    void displayMainMenu();

    void gameOver();
    void removeAll();    
    bool isundoit = true;
    void assignpast(Boxe *past);
    void assignpast1(Boxe *past);
    void undo();
public slots:
    void start();
private:
    QGraphicsScene *gameScene;
    QList <Piece *> whiteDead;
    QList <Piece *> blackDead;
    QGraphicsRectItem * deadHolder;
    QString turn;
    Board *chekers;
    QList <QGraphicsItem *> listG;
    QGraphicsTextItem * turnDisplay;



};

#endif // GAME_H
