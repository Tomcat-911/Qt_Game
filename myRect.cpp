#include "myRect.h"
#include <QGraphicsScene>
#include "QDebug"
#include <QKeyEvent>
#include "bullet.h"

void myRect::keyPressEvent(QKeyEvent *event)
{

    //qDebug() << "myRect knows that you pressed a key";

    if(event->key()== Qt::Key_Left)
    {
        setPos(x()-10,y());
    }

    else if(event->key()== Qt::Key_Right)
    {
        setPos(x()+10,y());
    }

 /* else if(event->key()== Qt::Key_Up)
    {
        setPos(x(),y()-10);
    }

    else if(event->key()== Qt::Key_Down)
    {
        setPos(x(),y()+10);
    }
*/
    else if (event->key() == Qt::Key_Space)
    {
        // create a bullet
        bullet * bullet1 = new bullet();
        bullet1->setPos(x(),y());
        scene()->addItem(bullet1);
    }

}
