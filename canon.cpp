#include "canon.h"

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>
#include <QTimer>

#include <QDebug>

Canon::Canon(int sceneWidth, int sceneHeight, QGraphicsItem *parent)
{
   setPixmap(QPixmap(":/sprites/sprites/canon.png"));

   m_canonOriginPoint = new QPointF(pixmap().size().width() / 2, pixmap().size().height());
   setPos(sceneWidth / 2 - pixmap().size().width() / 2, sceneHeight - pixmap().size().height());

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
    qDebug() << "Fire ! " << endl;
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
