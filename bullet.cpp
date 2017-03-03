#include "bullet.h"
#include <QPixmap>
#include <QTimer>

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/sprites/sprites/bullet.png"));

//    QTimer * timer = new QTimer(this);
//    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

//    // start the timer
//    timer->start(50);
}

void Bullet::handle(){
//    QObject::connect(timer,&QPushButton::clicked,this,&Chrono::startChrono);
}

void Bullet::move(){

}

