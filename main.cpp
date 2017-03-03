#include <QApplication>
#include "Game.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


//    QGraphicsRectItem *canon = new QGraphicsRectItem();
//    canon->setRect(0, 0, 100, 100);
//    scene->addItem(canon);


//    QGraphicsRectItem *elysee = new QGraphicsRectItem();
//    elysee->setRect(0, 0, 450, 200);
//    elysee->setPos(0,200);
////    QPixmap *elysee_pixel = new QPixmap(":/sprites/elysee.png");
//    scene->addItem(elysee);


//    QGraphicsView *view = new QGraphicsView();
//    view->setFixedSize(455, 705);
//    view->setScene(scene);

//    view->show();

    Game *game = new Game();
    game->show();

    return a.exec();
}


