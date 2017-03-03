#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene *scene = new QGraphicsScene();

    QGraphicsRectItem *canon = new QGraphicsRectItem();
    canon->setRect(0, 0, 100, 100);

    scene->addItem(canon);

    QGraphicsView *view = new QGraphicsView();
    view->setFixedSize(800, 600);
    view->setScene(scene);

    view->show();
    return a.exec();
}
