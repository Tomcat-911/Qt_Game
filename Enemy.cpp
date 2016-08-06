#include "Enemy.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"

extern Game *game;

Enemy::Enemy()
{

    //set random position
    int random_number = rand() % 700;
    setPos(random_number,0);

    // drew the rect
    setRect(0,0,100,100);

    // connect
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);

}

void Enemy::move()
{
    // move enemy down
    setPos(x(),y()+5);

    //destroy enemy when it goes out of the screen
    if (pos().y() /*+ rect().height()*/ >1000)
    {
        //decrease the health
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
        //qDebug() << "Enemy deleted";
    }
}


