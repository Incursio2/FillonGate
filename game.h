#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QPointer>
#include <ennemy.h>
#include <QList>

class Game: public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget * parent=0);
    QGraphicsScene * scene;
    QPointer<QTimer> m_timer;
    QList<Ennemy*> *ennemies;

    int m_playerScore;

public slots:
    void addEnnemy();
};

#endif // GAME_H
