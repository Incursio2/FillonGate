#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Bullet: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
    public:
        Bullet(QGraphicsItem * parent=0);

    private:
        QTimer timer;
        void fire();
};

#endif // BULLET_H
