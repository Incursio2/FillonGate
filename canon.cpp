#include "canon.h"

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>

#include <QDebug>

Canon::Canon(int sceneWidth, int sceneHeight)
{
   setPixmap(QPixmap(":/sprites/sprites/canon.png"));

   m_canonOriginPoint = new QPointF(pixmap().size().width() / 2, pixmap().size().height());
   setPos(sceneWidth / 2 - pixmap().size().width() / 2, sceneHeight - pixmap().size().height());
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

    if (rotation() + degree >= 45 && rotation() + degree <= 135)
        setRotation(rotation() + degree - 90);
}

void Canon::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{

}

void Canon::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
}
