#ifndef ENNEMY_H
#define ENNEMY_H

#include <QObject>
#include <QPointer>
#include <QGraphicsPixmapItem>
class QTimer;
class QGraphicsItem;

class Ennemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int m_speed, m_hp, m_sceneWidth, m_sceneHeight;
    QPointer<QTimer> m_timer;
    bool m_isNice;
    void init();

public:
    explicit Ennemy(QGraphicsItem *parent = 0);
    ~Ennemy();
    void setEnnemy();

public slots:
    void move();
};

#endif // ENNEMY_H
