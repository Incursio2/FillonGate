#ifndef CANON_H
#define CANON_H

#include <QObject>
#include <QGraphicsPixmapItem>

class QGraphicsSceneMouseEvent;
class QPointF;
class QTimer;

class Canon : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        Canon(int sceneWidth, int sceneHeight, QGraphicsItem * parent = 0);
        ~Canon();

    public slots:
        void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
        void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);

    private slots:
         void Fire();
    private:
         QPointF *m_canonOriginPoint;
         QTimer *m_timer;

        void Handle();
};

#endif // CANON_H
