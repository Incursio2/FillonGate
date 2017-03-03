#define _USE_MATH_DEFINES
#include "canon.h"

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>

#include <QDebug>

Canon::Canon()
{
   m_canonOriginPoint = new QPointF(245, 700);
   setRect(225, 600, 20, 100);
   setAcceptDrops(true);
}

Canon::~Canon()
{
    delete m_canonOriginPoint;
    m_canonOriginPoint = nullptr;
}

void Canon::mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
    QPointF mouseScenePos = mouseEvent->pos();

    float radian = atan2(m_canonOriginPoint->y() - mouseScenePos.y(), m_canonOriginPoint->x() - mouseScenePos.x());
    float degree = radian * 180 / M_PI;

    setTransformOriginPoint(*m_canonOriginPoint);
    setRotation(rotation() + degree - 90);
}

void Canon::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
}

void Canon::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
}
