#ifndef ELYSEE_H
#define ELYSEE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Elysee: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Elysee(QGraphicsItem * parent = 0);
};

#endif // ELYSEE_H
