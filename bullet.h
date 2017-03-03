#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>

class Bullet: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
    public:
        Bullet(QGraphicsItem * parent=0);
        ~Bullet();
        void start(int x, int y, float direction);

    private:
        QTimer *timer;
        float direction;
        void setPosAndRotation(int vitesse);
        void handle();
        void checkCollisions();
        void move();
};

#endif // BULLET_H
