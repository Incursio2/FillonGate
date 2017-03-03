#include "ennemy.h"
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <qmath.h>
#include <QTimer>
#include <QDebug>

Ennemy::Ennemy(QObject *parent) : QObject(parent)
{

}
Ennemy::Ennemy(QGraphicsScene *scene)
{
    m_scene = scene;
    init();
}
void Ennemy::init()
{
    m_isNice = (fmod(qrand(),100) > 75;
    m_h = 50;
    m_w = 50;
    m_posy = - m_h;
    m_speed = fmod(qrand(),4);
    m_posx = fmod(qrand(),m_scene->sceneRect().width() - m_w);
    m_pos = new QGraphicsEllipseItem(m_posx,m_posy,m_w,m_h);
    m_scene->addItem(m_pos);

    m_timer = new QTimer();

    connect(m_timer, SIGNAL(timeout()), this, SLOT(move()));
    m_timer->start(10);

}
void Ennemy::move()
{
    m_pos->setPos(m_pos->x(),m_pos->y() + m_speed);
}

Ennemy::~Ennemy()
{
    delete m_timer;
    m_timer = nullptr;
    delete m_pos;
    m_pos = nullptr;
}
