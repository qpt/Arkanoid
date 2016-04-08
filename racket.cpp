/*
  Copyright (c) 2016 David Hovhannisyan

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License as
  published by the Free Software Foundation; either version 2 of the
  License, or (at your option) any later version.  See the file
  LICENSE included with this distribution for more information.

*/

#include "racket.h"

Racket::Racket(int posx, int posy)
{
    QPixmap pix(":/img/racket.png");
    setBrush(pix);
    setRect(0,0,pix.width(),pix.height());
    setPos(posx,posy);
    GameEngine::instance()->getScene()->addItem(this);
}

Racket::~Racket()
{
    GameEngine::instance()->getScene()->removeItem(this);
}

void Racket::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
        if(pos().x() > 10)
           setPos(x()-10,y());
    if(event->key() == Qt::Key_Right)
        if(pos().x() < 440-10-rect().width())
             setPos(x()+10,y());
    if(event->key() == Qt::Key_Space)
    {
        //Bullet * bullet = new Bullet();
        //bullet->setPos(x(),y());
        //scene()->addItem(bullet);
    }
}
