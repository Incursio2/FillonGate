#ifndef ENNEMY_H
#define ENNEMY_H

#include <QObject>
#include <QPointer>
#include <QGraphicsPixmapItem>
class QGraphicsEllipseItem;
class QTimer;
class QGraphicsItem;

class Ennemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QGraphicsEllipseItem *m_pos;
    int m_speed, m_hp, m_sceneWidth, m_sceneHeight;
    QPointer<QTimer> m_timer;
    bool m_isNice;
    void init();
public:
    explicit Ennemy(int _sceneWidth, int _sceneHeight, QGraphicsPixmapItem *parent = 0);
    ~Ennemy();

signals:

public slots:
    void move();
};

#endif // ENNEMY_H
