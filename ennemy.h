#ifndef ENNEMY_H
#define ENNEMY_H

#include <QObject>
#include <QPointer>
class QGraphicsEllipseItem;
class QGraphicsScene;
class QTimer;

class Ennemy : public QObject
{
    Q_OBJECT

private:
    QGraphicsEllipseItem *m_pos;
    int m_speed, m_hp, m_posx, m_posy, m_h, m_w;
    QPointer<QTimer> m_timer;
    QGraphicsScene *m_scene;
    bool m_isNice;
    void init();
public:
    explicit Ennemy(QObject *parent = 0);
    Ennemy(QGraphicsScene *scene);
    ~Ennemy();

signals:

public slots:
    void move();
};

#endif // ENNEMY_H
