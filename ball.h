/*
  Copyright (c) 2016 David Hovhannisyan

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License as
  published by the Free Software Foundation; either version 2 of the
  License, or (at your option) any later version.  See the file
  LICENSE included with this distribution for more information.

*/

#ifndef BALL_H
#define BALL_H

#include <QGraphicsPixmapItem>
#include <QList>
#include <QTimer>
#include <typeinfo>
#include "game.h"

class Ball: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    Ball(int posx, int posy,QGraphicsItem* parent = 0);
    ~Ball();
private:
    QTimer *m_timer;
public slots:
    void move();
};

#endif // BALL_H
