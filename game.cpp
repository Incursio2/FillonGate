#include "Game.h"
#include "elysee.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>

Game::Game(QWidget *parent)
{

    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,450,700);
    setBackgroundBrush(QBrush(QImage(":/sprites/sprites/ciel.jpg")));
    setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(455,705);

    QGraphicsRectItem *canon = new QGraphicsRectItem();
    canon->setRect(0, 0, 100, 100);
    scene->addItem(canon);

    Elysee *elysee = new Elysee();
    elysee->setPos(0,480);
    scene->addItem(elysee);

    show();
}
