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
    for(int i=0;i<13;i++) {
        new Cube(false,Qt::gray,2,c_wstart+i*cubesHeight,c_hstart+cubesWidth*0,cubesHeight,cubesWidth);
        new Cube(true,Qt::red,2,c_wstart+i*cubesHeight,c_hstart+cubesWidth*1,cubesHeight,cubesWidth);
        new Cube(true,Qt::yellow,2,c_wstart+i*cubesHeight,c_hstart+cubesWidth*2,cubesHeight,cubesWidth);
        new Cube(true,Qt::blue,2,c_wstart+i*cubesHeight,c_hstart+cubesWidth*3,cubesHeight,cubesWidth);
        new Cube(true,Qt::cyan,2,c_wstart+i*cubesHeight,c_hstart+cubesWidth*4,cubesHeight,cubesWidth);
        new Cube(true,Qt::green,2,c_wstart+i*cubesHeight,c_hstart+cubesWidth*5,cubesHeight,cubesWidth);
    }
    Racket *player = new Racket(100,525);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
}
