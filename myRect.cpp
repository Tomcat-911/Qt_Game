#include "myRect.h"
#include <QGraphicsScene>
#include "QDebug"
#include <QKeyEvent>
#include "bullet.h"
#include "Enemy.h"


void myRect::keyPressEvent(QKeyEvent *event)
{

    //qDebug() << "myRect knows that you pressed a key";

    if(event->key()== Qt::Key_Left)
    {
        if(pos().x()>0)
        setPos(x()-10,y());
    }

    else if(event->key()== Qt::Key_Right)
    {
        if(pos().x() + 100 < 1200)
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

void myRect::spawn()
{
    // create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
