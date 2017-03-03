#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <ennemy.h>
#include "Game.h"

Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QGraphicsScene *scene = new QGraphicsScene(0,0,450,700);

    game = new Game();
    game->show();
    return a.exec();
}


