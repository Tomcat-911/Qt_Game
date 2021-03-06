#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <Enemy.h>

Game::Game(QWidget *parent)
{
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1200,1000); // make the scene 1200 x 1000 instead of infinity x infinity

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView widget
    // it can be used to visualize scenes
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1200,1000);

    // create the player
    player = new Player;
    player->setRect(0,0,100,100); // change the rect from 0x0 (default) to 100 x 100 pixels
    player->setPos(600,900); //TODO generalize to always be in the middle bottom of screen
    //make the player focusable ans set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);

    //create the score and health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(), health->y()+50);
    scene->addItem(health);

    // spawn enemies
    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    show();
}
