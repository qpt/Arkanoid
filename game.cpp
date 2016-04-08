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

unsigned char lvl_1[15][13] = {
    {   ub,     ub,     ub,     ub,     ub,     ub,     ub,     ub,     ub,     ub,     ub,     ub,     ub     },
    {   green,  green,  green,  green,  green,  green,  green,  green,  green,  green,  green,  green,  green  },
    {   cyan,   cyan,   cyan,   cyan,   cyan,   cyan,   cyan,   cyan,   cyan,   cyan,   cyan,   cyan,   cyan    },
    {   blue,   blue,   blue,   blue,   blue,   blue,   blue,   blue,   blue,   blue,   blue,   blue,   blue    },
    {   yellow, yellow, yellow, yellow, yellow, yellow, yellow, yellow, yellow, yellow, yellow, yellow, yellow  },
    {   red,    red,    red,    red,    red,    red,    red,    red,    red,    red,    red,    red,    red     },
    {   empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty   },
    {   empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty   },
    {   empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty   },
    {   empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty   },
    {   empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty   },
    {   empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty   },
    {   empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty   },
    {   empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty   },
    {   empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty,  empty   }
};


unsigned char lvl_2[15][13] = {
    {   empty,  empty,  empty,  ub,     ub,     empty,  empty,  empty,  ub,     ub,     empty,  empty,  empty   },
    {   empty,  empty,  ub,     yellow, yellow, ub,     empty,  ub,     red,    red,    ub,     empty,  empty   },
    {   empty,  ub,     yellow, yellow, yellow, yellow, ub,     red,    red,    red,    red,    ub,     empty   },
    {   empty,  ub,     yellow, yellow, yellow, yellow, yellow, red,    red,    red,    red,    ub,     empty   },
    {   ub,     yellow, yellow, yellow, yellow, yellow, red,    red,    red,    red,    red,    red,    ub      },
    {   ub,     yellow, yellow, yellow, yellow, yellow, yellow, red,    red,    red,    red,    red,    ub      },
    {   ub,     yellow, yellow, yellow, yellow, yellow, red,    red,    red,    red,    red,    red,    ub      },
    {   cyan,   yellow, yellow, yellow, yellow, yellow, yellow, red,    red,    red,    red,    red,    cyan    },
    {   empty,  cyan,   yellow, yellow, yellow, yellow, red,    red,    red,    red,    red,    cyan,   empty   },
    {   empty,  cyan,   yellow, yellow, yellow, yellow, yellow, red,    red,    red,    red,    cyan,   empty   },
    {   empty,  empty,  cyan,   yellow, yellow, yellow, red,    red,    red,    red,    cyan,   empty,  empty   },
    {   empty,  empty,  empty,  cyan,   yellow, yellow, yellow, red,    red,    cyan,   empty,  empty,  empty   },
    {   empty,  empty,  empty,  empty,  cyan,   yellow, red,    red,    cyan,   empty,  empty,  empty,  empty   },
    {   empty,  empty,  empty,  empty,  empty,  cyan,   yellow, cyan,   empty,  empty,  empty,  empty,  empty   },
    {   empty,  empty,  empty,  empty,  empty,  empty,  cyan,  empty,   empty,  empty,  empty,  empty,  empty   }
};

unsigned char lvl_3[15][13] = {
    {   empty,  empty,  empty,  yellow, empty,  empty,  empty,  empty,  empty,  yellow, empty,  empty,  empty   },
    {   empty,  empty,  empty,  yellow, empty,  empty,  empty,  empty,  empty,  yellow, empty,  empty,  empty   },
    {   empty,  empty,  empty,  empty,  yellow, empty,  empty,  empty,  yellow, empty,  empty,  empty,  empty   },
    {   empty,  empty,  empty,  empty,  yellow, empty,  empty,  empty,  yellow, empty,  empty,  empty,  empty   },
    {   empty,  empty,  empty,  green,  green,  green,  green,  green,  green,  green,  empty,  empty,  empty   },
    {   empty,  empty,  empty,  green,  green,  green,  green,  green,  green,  green,  empty,  empty,  empty   },
    {   empty,  empty,  green,  green,  red,    green,  green,  green,  red,    green,  green,  empty,  empty   },
    {   empty,  empty,  green,  green,  red,    green,  green,  green,  red,    green,  green,  empty,  empty   },
    {   empty,  green,  green,  green,  green,  green,  green,  green,  green,  green,  green,  green,  empty   },
    {   empty,  green,  green,  green,  green,  green,  green,  green,  green,  green,  green,  green,  empty   },
    {   empty,  green,  green,  green,  green,  green,  green,  green,  green,  green,  green,  green,  empty   },
    {   empty,  green,  empty,  green,  green,  green,  green,  green,  green,  green,  empty,  green,  empty   },
    {   empty,  green,  empty,  green,  empty,  empty,  empty,  empty,  empty,  green,  empty,  green,  empty   },
    {   empty,  green,  empty,  green,  empty,  empty,  empty,  empty,  empty,  green,  empty,  green,  empty   },
    {   empty,  empty,  empty,  empty,  green,  green,  empty,  green,  green,  empty,  empty,  empty,  empty   }
};

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
    player = new Racket(100,520);
    mtx = new CubeMatrix;
    ball = new Ball(100,400);
    mtx->fillLevel(lvl_1);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
}

void GameEngine::cleanup()
{
    delete ball;
    delete player;
    delete mtx;

    ball = NULL;
    player = NULL;
    mtx = NULL;
}
