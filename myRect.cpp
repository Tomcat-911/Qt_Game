#include "myRect.h"
#include "QDebug"
#include <QKeyEvent>

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

    else if(event->key()== Qt::Key_Up)
    {
        setPos(x(),y()-10);
    }

    else if(event->key()== Qt::Key_Down)
    {
        setPos(x(),y()+10);
    }

}
