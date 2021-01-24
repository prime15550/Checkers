//-----------------------------------------------------
// Title: main
// Author: Deniz Dumanlı, Tunç Gürsoy
// ID: 25337236168, 64528127274
// Section: 1
// Assignment: 3
// Description: This class runs the program.
//-----------------------------------------------------
#include <QApplication>
#include "game.h"

Game *game;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game = new Game();

    game->setFixedSize(1400,900);
    game->displayMainMenu();
    game->show();
    return a.exec();

}
