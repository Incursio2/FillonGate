#include "bullet.h"
#include <QPixmap>
#include <QTimer>
#include <QPoint>
#include <QGraphicsScene>
#include <QtMath>
#include <QPointF>

#include <QDebug>

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    timer = new QTimer(this);
    handle();
}

void Bullet::start(int x, int y, float direction_){
    setPixmap(QPixmap(":/sprites/sprites/balle.png"));
    setPos(x,y);
    direction = direction_;
    timer->start(50);
}

void Bullet::handle(){
    QObject::connect(timer, &QTimer::timeout, this, &Bullet::move);
}

void Bullet::move(){
    // Calculer la nouvelle position de la balle en fonction de la direction.
    int vitesse = 5;

    qreal posX = pos().x() + qCos(qDegreesToRadians(direction))*vitesse;
    qreal posY = pos().y() - qSin(qDegreesToRadians(direction))*vitesse;

    float radian = atan2(pos().y() - posY, pos().x() - posX);
    float degree = radian * 180 / M_PI;

    setRotation(degree - 90);
    setPos(posX, posY-vitesse);

    // Si la balle sort de l'écran on la détruit.
    if(!scene()->sceneRect().contains(QPoint(pos().x(),pos().y()))){
        scene()->removeItem(this);
        delete this;
    }

}

Bullet::~Bullet()
{
    //timer->killTimer
    delete timer;
    timer = nullptr;
}

