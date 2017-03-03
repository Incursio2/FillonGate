#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <ennemy.h>
#include "Game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QGraphicsScene *scene = new QGraphicsScene(0,0,450,700);

//    QGraphicsEllipseItem *circle = new QGraphicsEllipseItem(0,0,50,50);

//    //canon->setRect(0, 0, 100, 100);
//    QLine originLine = QLine(0,0,450,0);
//    scene->addItem(circle);
//    scene->addLine(originLine);
//    new Ennemy(scene);
//    new Ennemy(scene);
//    new Ennemy(scene);
//    new Ennemy(scene);
//    new Ennemy(scene);
//    new Ennemy(scene);
//    new Ennemy(scene);

//    QGraphicsView *view = new QGraphicsView();
//    view->setFixedSize(455, 705);
//    view->setScene(scene);

//    view->show();
    Game *game = new Game();
    game->show();
    return a.exec();
}


