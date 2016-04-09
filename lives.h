/*
  Copyright (c) 2016 David Hovhannisyan

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License as
  published by the Free Software Foundation; either version 2 of the
  License, or (at your option) any later version.  See the file
  LICENSE included with this distribution for more information.

*/

#ifndef LIVES_H
#define LIVES_H

#include "game.h"

class Lives: public QGraphicsTextItem {
public:
    Lives(QGraphicsItem* parent=0);
    ~Lives();
    void decrease();
    int getLives();
private:
    int m_lives;
};

#endif // LIVES_H
