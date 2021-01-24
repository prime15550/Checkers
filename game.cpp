//-----------------------------------------------------
// Title: game
// Author: Deniz Dumanlı, Tunç Gürsoy
// ID: 25337236168, 64528127274
// Section: 1
// Assignment: 2
// Description: This creates the additional buttons.
//-----------------------------------------------------

#include "game.h"
#include "button.h"
#include "king.h"
#include <QPixmap>
#include <QDebug>
#include <QMessageBox>
#include "popup.h"

Game::Game(QWidget *parent): QGraphicsView(parent)

{
    //Making the Scene
    gameScene = new QGraphicsScene();
    repaint();

    //Making the view

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(gameScene);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    setBackgroundBrush(brush);
    pieceToMove = NULL;

    //display turn
    turnDisplay = new QGraphicsTextItem();
    turnDisplay->setPos(0,0);
    turnDisplay->setZValue(1);
    turnDisplay->setDefaultTextColor(Qt::white);
    turnDisplay->setPlainText("Turn : WHITE");

    //display Check
    check = new QGraphicsTextItem();
    check->setPos(width()/2-100,860);
    check->setZValue(4);
    check->setDefaultTextColor(Qt::red);
    check->setFont(QFont("",18));
    check->setPlainText("CHECK!");
    check->setVisible(false);
    setTurn("WHITE");

}

// This method draws the board.
void Game::drawBoard()
{

    chekers = new Board(width(),height());

     chekers->drawBoxes(width()/10,50,width()-width()/10,height());

}
// These two assignpast methods are for undo feature.
void Game::assignpast(Boxe* item)
{
    this->past = item;
}

void Game::assignpast1(Boxe* item)
{
    this->past1 = item;
}


// This method adds item to scene.
void Game::addToScene(QGraphicsItem *item)
{
    gameScene->addItem(item);
}

// This method removes item from the scene.
void Game::removeFromScene(QGraphicsItem *item)
{
    gameScene->removeItem(item);

}

QString Game::getTurn()
{
    return turn;
}

void Game::setTurn(QString value)
{
    turn = value;
}

// This method is for undo operation.
void Game::undo()
{
    if(!isundoit){
    Piece* a = past1->currentPiece;
    past->placePiece(a);
    past1->setHasPiece(false);
    past1->resetOriginalColor();
    past1->currentPiece = NULL;
    changeTurn();
    isundoit = true;
    }

}

// This method displays the who's turn is it.
void Game::changeTurn()
{
    if(getTurn() == "WHITE")
        setTurn("BLACK");
    else
        setTurn("WHITE");
    turnDisplay->setPlainText("Turn : " + getTurn());
}

// This method stars the game.
void Game::start()
{
    addToScene(turnDisplay);
    chekers->addPiece();
}


// This method displays the buttons.
void Game::displayMainMenu()
{

    Button * fileBut = new Button("File",width()/6,height()/20);
    fileBut->setPos(40+1.5*(width()/6-fileBut->boundingRect().width()/2),0);
    addToScene(fileBut);
    listG.append(fileBut);

    Button * editBut = new Button("Edit",width()/6,height()/20);
    editBut->setPos(40+3.5*(width()/6-fileBut->boundingRect().width()/2),0);
    addToScene(editBut);
    listG.append(editBut);

    Button * gameBut = new Button("Game",width()/6,height()/20);
    gameBut->setPos(40+5.5*(width()/6-fileBut->boundingRect().width()/2),0);
    addToScene(gameBut);
    listG.append(gameBut);


    Button * helpBut = new Button("Help",width()/6,height()/20);
    helpBut->setPos(40+7.5*(width()/6-fileBut->boundingRect().width()/2),0);
    addToScene(helpBut);
    listG.append(helpBut);

    Button * newGameBut = new Button("New-Game",width()/11,height()/20);
    newGameBut->setPos(0,height()/3);
    addToScene(newGameBut);
    listG.append(newGameBut);
    Button * undonewGameBut = new Button("Undo",width()/11,height()/20);
    undonewGameBut->setPos(0,height()/3+height()/20);
    addToScene(undonewGameBut);
    listG.append(undonewGameBut);

    Button * leftBut = new Button("<-",width()/33,height()/18);
    leftBut->setPos(0,2*height()/3);
    addToScene(leftBut);
    listG.append(leftBut);

    Button * upBut = new Button("^\n |",width()/33,height()/18);
    upBut->setPos(width()/33,2*height()/3);
    addToScene(upBut);
    listG.append(upBut);

    Button * rightBut = new Button("->",width()/33,height()/18);
    rightBut->setPos(2*width()/33,2*height()/3);
    addToScene(rightBut);
    listG.append(rightBut);

    drawBoard();
    start();
}

// This method runs when game is over.
void Game::gameOver()
{
    //removeAll();
    setTurn("WHITE");
    alivePiece.clear();
    chekers->reset();
    isundoit = true;

}

// This method removes everything from the scene.
void Game::removeAll(){
    QList<QGraphicsItem*> itemsList = gameScene->items();
    for(size_t i = 0, n = itemsList.size();i<n;i++) {
        if(itemsList[i]!=check)
          removeFromScene(itemsList[i]);
    }
}



