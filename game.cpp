/*
  Copyright (c) 2016 David Hovhannisyan

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License as
  published by the Free Software Foundation; either version 2 of the
  License, or (at your option) any later version.  See the file
  LICENSE included with this distribution for more information.

*/

#include "game.h"


GameEngine* GameEngine::s_instance;

void GameEngine::setScene(QGraphicsScene *p_scene)
{
    m_scene = p_scene;
}

QGraphicsScene *GameEngine::getScene() const
{
    return m_scene;
}

void GameEngine::startNewGame()
{
    for(int i=0;i<23;i++) {
        new Cube(true,Qt::red,2,0+i*cubesHeight,0,cubesHeight,cubesWidth);
        new Cube(true,Qt::blue,2,0+i*cubesHeight,cubesWidth,cubesHeight,cubesWidth);
        new Cube(true,Qt::green,2,0+i*cubesHeight,cubesWidth*2,cubesHeight,cubesWidth);
        new Cube(true,Qt::yellow,2,0+i*cubesHeight,cubesWidth*3,cubesHeight,cubesWidth);
        new Cube(true,Qt::gray,2,0+i*cubesHeight,cubesWidth*4,cubesHeight,cubesWidth);
    }
}
