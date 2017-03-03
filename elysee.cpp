#include "elysee.h"
#include <QPixmap>


Elysee::Elysee(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/sprites/sprites/elysee.png"));
}
