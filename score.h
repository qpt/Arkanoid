/*
  Copyright (c) 2016 David Hovhannisyan

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License as
  published by the Free Software Foundation; either version 2 of the
  License, or (at your option) any later version.  See the file
  LICENSE included with this distribution for more information.

*/

#ifndef SCORE_H
#define SCORE_H

#include "game.h"

class Score: public QGraphicsTextItem {
public:
    Score(QGraphicsItem* parent=0);
    ~Score();
    void increase();
    void updateScore();
    int getScore();
private:
    int m_score;
};
#endif // SCORE_H
