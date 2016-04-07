/*
  Copyright (c) 2016 David Hovhannisyan

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License as
  published by the Free Software Foundation; either version 2 of the
  License, or (at your option) any later version.  See the file
  LICENSE included with this distribution for more information.

*/

#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QVariant>

#include "cube.h"
#include "ball.h"
#include "racket.h"
#include "lives.h"
#include "score.h"

const int c_wstart = 6*2;
const int c_hstart = 60+7*2+40;
const int cubesWidth = 16;
const int cubesHeight = 32;

class GameEngine {
public:
    void setScene(QGraphicsScene* );
    QGraphicsScene* getScene() const;
    void startNewGame();

    static GameEngine *instance()
    {
        if (!s_instance)
        {
          s_instance = new GameEngine;
        }
        return s_instance;
    }
private:
    QGraphicsScene *m_scene;

    static GameEngine *s_instance;
    GameEngine(){}
};

#endif // GAME_H
