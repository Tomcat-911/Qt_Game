#include "Player.h"
#include <QGraphicsScene>
#include "QDebug"
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"


void Player::keyPressEvent(QKeyEvent *event)
{

    //qDebug() << "Player knows that you pressed a key";

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
        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
    }

}

void Player::spawn()
{
    // create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
