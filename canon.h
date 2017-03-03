#ifndef CANON_H
#define CANON_H

class QGraphicsSceneMouseEvent;
class QPointF;

#include <QGraphicsRectItem>

class Canon : public QGraphicsRectItem
{
    public:
        Canon();
        ~Canon();

        QPointF *m_canonOriginPoint;

public slots:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);

private:

};

#endif // CANON_H