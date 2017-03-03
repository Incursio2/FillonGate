#include "Game.h"
#include "elysee.h"
#include "canon.h"

#include <QGraphicsScene>
#include <QGraphicsRectItem>

Game::Game(QWidget *parent)
{

    QGraphicsScene *scene = new QGraphicsScene(0, 0, 450, 700);
    setBackgroundBrush(QBrush(QImage(":/sprites/sprites/ciel.jpg")));
    setScene(scene);

    QGraphicsTextItem *score = new QGraphicsTextItem();
    score->setPlainText("Score : ");
    score->setPos(10, 10);

    scene->addItem(score);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(450,700);

    Elysee *elysee = new Elysee();
    elysee->setPos(0,480);
    scene->addItem(elysee);

    Canon *canon = new Canon();
    scene->addItem(canon);
    canon->SetPosition();

    show();
}


