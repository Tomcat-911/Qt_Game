#include <QApplication>
#include <QGraphicsScene>
#include  "myRect.h"
#include <QGraphicsView>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();


    // create an item to put into the scene
    myRect * rect = new myRect();
    rect->setRect(0,0,100,100);

    // add the item to the scene
    scene->addItem(rect);

    // make the item focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();


    // add a view
    QGraphicsView *view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

     view->show();

    return a.exec();
}
