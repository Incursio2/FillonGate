#include "ennemy.h"
#include <QGraphicsEllipseItem>
#include <qmath.h>
#include <QTimer>
#include <QDebug>
#include <QGraphicsItem>

Ennemy::Ennemy(int _sceneWidth, int _sceneHeight,QGraphicsPixmapItem *parent):QGraphicsPixmapItem(parent)
{
//    m_sceneHeight = _sceneHeight;
//    m_sceneWidth = _sceneWidth;
//    init();
}
void Ennemy::init()
{

    m_isNice = fmod(qrand(),100) > 75;

    if (m_isNice) {
        this->setPixmap(QPixmap(":/sprites/sprites/juppe.png"));
    }else {
        this->setPixmap(QPixmap(":/sprites/sprites/fillon.png"));
    }

    this->pos().setY(- this->pixmap().height());
    m_speed = fmod(qrand(),4);
    this->pos().setX(fmod(qrand(), m_sceneWidth - this->pixmap().width()));

    m_timer = new QTimer();

    connect(m_timer, SIGNAL(timeout()), this, SLOT(move()));
    m_timer->start(10);
    qDebug() << "testitude" << endl;

}
void Ennemy::move()
{
    if (m_pos->y() > m_sceneHeight) {
        delete this;
        return;
    }
    m_pos->setPos(m_pos->x(),m_pos->y() + m_speed);
}

Ennemy::~Ennemy()
{
    delete m_timer;
    m_timer = nullptr;
    delete m_pos;
    m_pos = nullptr;
}
