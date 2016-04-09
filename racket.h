/*
  Copyright (c) 2016 David Hovhannisyan

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License as
  published by the Free Software Foundation; either version 2 of the
  License, or (at your option) any later version.  See the file
  LICENSE included with this distribution for more information.

*/

#ifndef RACKET_H
#define RACKET_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "game.h"

class Racket: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    Racket(int posx, int posy,QGraphicsItem* parent=0);
    ~Racket();

    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);

protected:
    void timerEvent(QTimerEvent *event=0);

private:
    bool is_moving_left, is_moving_right;
};

#endif // RACKET_H
