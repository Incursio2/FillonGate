#include "Game.h"
#include "elysee.h"
#include "canon.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QList>
#include <QFile>

#include <QDebug>

Game::Game(QWidget *parent)
{
    QFile file(":/styles/style.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    file.close();
    setStyleSheet(styleSheet);


    scene = new QGraphicsScene(0, 0, 450, 700);
    setBackgroundBrush(QBrush(QImage(":/sprites/sprites/ciel.jpg")));
    setScene(scene);

    txt_score = new QGraphicsTextItem();
    txt_score->setPlainText("Score : 0");
    txt_score->setScale(3);
    txt_score->setDefaultTextColor(QColor(255,255,255));

    txt_score->setObjectName("score");
    txt_score->setPos(10, 10);
    score = 0;

    scene->addItem(txt_score);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(450,700);

    Elysee *elysee = new Elysee();
    elysee->setPos(0,480);
    scene->addItem(elysee);

    Canon *canon = new Canon();
    scene->addItem(canon);
    canon->SetPosition();

    show();

    ennemies = new QList<Ennemy*>();
    addEnnemy();

    m_timer = new QTimer();

    connect(m_timer, SIGNAL(timeout()), this, SLOT(addEnnemy()));
    m_timer->start(1452);

}

void Game::addEnnemy()
{    
    Ennemy *ennemy = new Ennemy();
    scene->addItem(ennemy);
    ennemy->setEnnemy();
    ennemies->push_back(ennemy);
}

Game::~Game(){
    delete txt_score;
    txt_score = nullptr;
    delete scene;
    scene = nullptr;
    delete ennemies;
    ennemies = nullptr;
}

