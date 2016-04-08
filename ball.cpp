/*
  Copyright (c) 2016 David Hovhannisyan

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License as
  published by the Free Software Foundation; either version 2 of the
  License, or (at your option) any later version.  See the file
  LICENSE included with this distribution for more information.

*/

#include "ball.h"

Ball::Ball(int posx, int posy)
{
    QPixmap pix(":/img/ball.png");
    setBrush(pix);
    setRect(0,0,pix.width(),pix.height());
    setPos(posx,posy);
    GameEngine::instance()->getScene()->addItem(this);
}

Ball::~Ball()
{
    GameEngine::instance()->getScene()->removeItem(this);
}
