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

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include "game.h"

class Racket: public QObject, public QGraphicsRectItem {
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    Racket(int posx, int posy);
    ~Racket();

    void keyPressEvent(QKeyEvent * event);
};

#endif // RACKET_H
