#include "ennemy.h"
#include <QGraphicsEllipseItem>
#include <qmath.h>
#include <game.h>
#include <QTimer>
#include <QDebug>
#include <QGraphicsItem>
#include <QPixmap>
#include <QGraphicsScene>
#include <QDebug>

extern Game *game;

Ennemy::Ennemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    init();
}
void Ennemy::init()
{

    m_isNice = fmod(qrand(),100) > 90;

    if (m_isNice) {
        this->setPixmap(QPixmap(":/sprites/sprites/juppe.png"));
    }else {
        this->setPixmap(QPixmap(":/sprites/sprites/fillon.png"));
    }

    m_speed = fmod(qrand(),4);

    m_timer = new QTimer();

    connect(m_timer, SIGNAL(timeout()), this, SLOT(move()));
    m_timer->start(10);

}
void Ennemy::setEnnemy()
{
    setPos(fmod(qrand(), scene()->width() - this->pixmap().width()),- this->pixmap().height());
}

void Ennemy::move()
{
    if (this->pos().y() > scene()->height()) {
        game->ennemies->removeAt(game->ennemies->indexOf(this));
        delete this;
        return;
    }
    setPos(this->pos().x(),this->pos().y() + m_speed);
}

Ennemy::~Ennemy()
{
    delete m_timer;
    m_timer = nullptr;
//    delete m_pos;
//    m_pos = nullptr;
}
