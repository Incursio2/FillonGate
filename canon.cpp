#include "canon.h"
#include "bullet.h"

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>
#include <QTimer>
#include <QtMath>
#include <QTime>

#include <QDebug>


Canon::Canon(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
   setPixmap(QPixmap(":/sprites/sprites/canon.png"));

   m_canonOriginPoint = new QPointF(pixmap().size().width() / 2, pixmap().size().height());
//   canon->setPos(scene()->width() / 2 - pixmap().size().width() / 2, scene()->height() - pixmap().size().height());

   m_timer = new QTimer(this);
   m_timer->start(500);
   Canon::Handle();
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
    qsrand(QTime::currentTime().msec());
    int angle = rand() % 150 + 15; // Entre 15 et 149
    qDebug() << "Angle" << angle;
    balle->start(210,590,angle);
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
