#include "canon.h"
#include "bullet.h"

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>
#include <QGraphicsScene>
#include <QTimer>
#include <QtMath>
#include <QTime>

#include <QDebug>


Canon::Canon(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
   setPixmap(QPixmap(":/sprites/sprites/canon.png"));
   m_canonOriginPoint = new QPointF(pixmap().size().width() / 2, pixmap().size().height());
   m_timer = new QTimer(this);
   m_timer->start(500);
   Canon::Handle();
}

void Canon::SetPosition()
{
    setPos(scene()->width() / 2 - pixmap().size().width() / 2, scene()->height() - pixmap().size().height());
}

Canon::~Canon()
{
    delete m_canonOriginPoint;
    m_canonOriginPoint = nullptr;

    delete m_timer;
    m_timer = nullptr;
}

void Canon::Handle()
{
    m_timer->connect(m_timer, &QTimer::timeout, this,  &Canon::Fire);
}

void Canon::Fire()
{
    Bullet *balle = new Bullet();

    float angle = abs(rotation() - 90);
    float rayon = pixmap().size().height();

    float posX = rayon * qCos(angle * M_PI / 180) + scene()->width() / 2 - 13;
    float posY = rayon * qSin(angle * M_PI / 180)+ scene()->height() - pixmap().size().height() * 2 - 25;

    balle->start(posX, posY, angle);
    scene()->addItem(balle);
}

void Canon::mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
    QPointF mouseScenePos = mouseEvent->pos();

    float radian = atan2(m_canonOriginPoint->y() - mouseScenePos.y(), m_canonOriginPoint->x() - mouseScenePos.x());
    float degree = radian * 180 / M_PI;

    setTransformOriginPoint(*m_canonOriginPoint);

    if (rotation() + degree >= 45 && rotation() + degree <= 135)
        setRotation(rotation() + degree - 90);
}

void Canon::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{

}

void Canon::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
}
