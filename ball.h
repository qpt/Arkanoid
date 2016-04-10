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

#define M_PI    3.14159265358979323846

#include <QGraphicsPixmapItem>
#include <QtMath>
#include <QList>
#include <QTimer>
#include "game.h"

class Ball: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    Ball(int posx, int posy,qreal v,qreal phi,QGraphicsItem* parent = 0);
    void changeDirection(qreal);
    void changeSpeed(qreal);
    ~Ball();
private:
    QTimer *m_timer;
    qreal m_angle;
public slots:
    void move();
};

#endif // BALL_H
