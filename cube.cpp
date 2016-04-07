/*
  Copyright (c) 2016 David Hovhannisyan

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License as
  published by the Free Software Foundation; either version 2 of the
  License, or (at your option) any later version.  See the file
  LICENSE included with this distribution for more information.

*/

#include "cube.h"

Cube::Cube(bool brk,Qt::GlobalColor clr,int hlth,int posx, int posy, int w, int h):
    m_breakability(brk), m_health(hlth)
{
    setRect(0,0,w,h);
    setPos(posx,posy);
    setBrush(QBrush(clr));
    GameEngine::instance()->getScene()->addItem(this);
}

Cube::~Cube()
{
    GameEngine::instance()->getScene()->removeItem(this);
}
