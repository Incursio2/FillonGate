#include "bullet.h"
#include "game.h"

#include <QPixmap>
#include <QTimer>
#include <QPoint>
#include <QGraphicsScene>
#include <QtMath>
#include <QPointF>
#include <QBrush>
#include <QImage>
#include <QList>

#include <QDebug>

extern Game *game;

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    timer = new QTimer(this);
    handle();
}

void Bullet::start(int x, int y, float direction_){
    setPixmap(QPixmap(":/sprites/sprites/balle.png"));
    setPos(x,y);
    direction = direction_;
    setPosAndRotation(1);
    timer->start(50);
}

void Bullet::handle(){
    QObject::connect(timer, &QTimer::timeout, this, &Bullet::move);
}

void Bullet::move(){
    // Calculer la nouvelle position de la balle en fonction de la direction.    
    setPosAndRotation(10);
    if(!checkCollisions()){
        // Si la balle sort de l'écran on la détruit.
        if(!scene()->sceneRect().contains(QPoint(pos().x(),pos().y()+60))){
            scene()->removeItem(this);
            delete this;
        }
    }
}

void Bullet::setPosAndRotation(int vitesse){
    qreal posX = pos().x() + qCos(qDegreesToRadians(direction))*vitesse;
    qreal posY = pos().y() - qSin(qDegreesToRadians(direction))*vitesse;

    float radian = atan2(pos().y() - posY, pos().x() - posX);
    float degree = radian * 180 / M_PI;

    setRotation(degree-90);
    setPos(posX,posY-vitesse);
}

bool Bullet::checkCollisions(){
//    qDebug() << "Nb ennemies" << game->ennemies->count();
    QList<QGraphicsItem *> items_collision = collidingItems();
    for(int e=0; e < items_collision.count();++e){
        if (typeid(*(items_collision.at(e))) == typeid(Ennemy)){
            qDebug() << "COLLISSION" << endl;
            scene()->removeItem(items_collision.at(e));
            delete items_collision[e];

            qDebug() << "COLLISSION 1" << endl;

            scene()->removeItem(this); // On supprime la balle.
            delete this;

            qDebug() << "COLLISSION 2" << endl;

            return true;
        }
    }
    return false;
 }

Bullet::~Bullet()
{
    //timer->killTimer
    delete timer;
    timer = nullptr;
}

