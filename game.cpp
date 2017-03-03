#include "Game.h"
#include "elysee.h"
#include "ennemy.h"
#include "canon.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QDebug>

Game::Game(QWidget *parent)
{

    scene = new QGraphicsScene(0, 0, 450, 700);
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

    Ennemy *ennemy = new Ennemy();
    ennemy->setPos(30,50);
    scene->addItem(ennemy);

    m_timer = new QTimer();

    connect(m_timer, SIGNAL(timeout()), this, SLOT(addEnnemy()));
    m_timer->start(1452);

}

void Game::addEnnemy()
{
    Ennemy *ennemy = new Ennemy();
    scene->addItem(ennemy);
    ennemy->setEnnemy();
}


