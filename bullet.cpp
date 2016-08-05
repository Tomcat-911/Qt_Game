#include "bullet.h"
#include <QTimer>


bullet::bullet()
{
    // drew the rect
    setRect(0,0,10,50);

    // connect
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);

}

void bullet::move()
{
    // move the bullet up
    setPos(x(),y()-10);
}
