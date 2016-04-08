/*
  Copyright (c) 2016 David Hovhannisyan

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License as
  published by the Free Software Foundation; either version 2 of the
  License, or (at your option) any later version.  See the file
  LICENSE included with this distribution for more information.

*/

#include "racket.h"

Racket::Racket(int posx, int posy, QGraphicsItem* parent):QObject(),QGraphicsPixmapItem(parent)
{
    QPixmap pix(":/img/racket.png");
    pix = pix.scaled(pix.width()*2,pix.height()*2, Qt::KeepAspectRatio, Qt::FastTransformation);
    setPixmap(pix);
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
        if(pos().x() > 12)
           setPos(x()-10,y());
    if(event->key() == Qt::Key_Right)
        if(pos().x() < 440 - 12 - sceneBoundingRect().width())
            setPos(x()+10,y());
}
