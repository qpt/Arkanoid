/*
  Copyright (c) 2016 David Hovhannisyan

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License as
  published by the Free Software Foundation; either version 2 of the
  License, or (at your option) any later version.  See the file
  LICENSE included with this distribution for more information.

*/

#ifndef CUBE_H
#define CUBE_H

#include <QRect>
#include <QGraphicsRectItem>
#include "game.h"

class Cube: public QObject, public QGraphicsRectItem {
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    Cube(bool brk,Qt::GlobalColor clr,int hlth,int posx, int posy, int w, int h);
    ~Cube();
private:
    QRect *m_rect;
    bool m_breakability;
    int m_health;
};

class CubeFactory
{
public:
    CubeFactory();
};

#endif // CUBE_H
