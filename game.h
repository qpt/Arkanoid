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

class GameImplementer {
public:
    void setScene(QGraphicsScene*);

    static GameImplementer *instance()
    {
        if (!s_instance)
        {
          s_instance = new GameImplementer;
        }
        return s_instance;
    }
private:
    QGraphicsScene *m_scene;

    static GameImplementer *s_instance;
    GameImplementer(){}
};

#endif // GAME_H
