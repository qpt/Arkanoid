/*
  Copyright (c) 2016 David Hovhannisyan

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License as
  published by the Free Software Foundation; either version 2 of the
  License, or (at your option) any later version.  See the file
  LICENSE included with this distribution for more information.

*/

#include "game.h"

GameImplementer* GameImplementer::s_instance;

void GameImplementer::setScene(QGraphicsScene *p_scene)
{
    m_scene = p_scene;
}
