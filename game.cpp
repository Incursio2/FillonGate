#include "Game.h"
#include "elysee.h"
#include "ennemy.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QDebug>

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


    m_timer = new QTimer();

    connect(m_timer, SIGNAL(timeout()), this, SLOT(addEnnemy()));
    m_timer->start(1000);

}

void Game::addEnnemy()
{
    Ennemy *ennemy = new Ennemy(450,700);
    qDebug() << "testitude" << endl;
    scene->addItem(ennemy);
    qDebug() << "222" << endl;
}
