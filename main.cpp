#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QGraphicsItem>

#include "canon.h"
#include "gameView.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene *scene = new QGraphicsScene(0, 0, 450, 700);

    Canon *canon = new Canon();
    scene->addItem(canon);

    QGraphicsView *view = new QGraphicsView(scene);
    view->setFixedSize(455, 705);
    view->setMouseTracking(true);
    view->show();

    return a.exec();
}
