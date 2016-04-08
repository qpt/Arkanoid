/*
  Copyright (c) 2016 David Hovhannisyan

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License as
  published by the Free Software Foundation; either version 2 of the
  License, or (at your option) any later version.  See the file
  LICENSE included with this distribution for more information.

*/

#include "ball.h"
#include <QDebug>

Ball::Ball(int posx, int posy, QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    QPixmap pix(":/img/ball.png");
    pix = pix.scaled(pix.width()*2,pix.height()*2, Qt::KeepAspectRatio, Qt::FastTransformation);
    setPixmap(pix);
    setPos(posx,posy);
    GameEngine::instance()->getScene()->addItem(this);
    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(5);
}

Ball::~Ball()
{
    GameEngine::instance()->getScene()->removeItem(this);
}

void Ball::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i )
    {
       if(typeid(*(colliding_items[i])) == typeid(Cube))
       {
            qDebug(" y0000 ");
       }
    }
    setPos(x(),y()-1);
}
