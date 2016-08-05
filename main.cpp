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
    myRect * player = new myRect();
    player->setRect(0,0,100,100);

    // add the item to the scene
    scene->addItem(player);

    // make the item focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();


    // add a view
    QGraphicsView *view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

     view->show();
     view->setFixedSize(1200,1000);
     scene->setSceneRect(0,0,1200,1000);

     player->setPos(view->width()/2, view->height()- player->rect().height() );

    return a.exec();
}
