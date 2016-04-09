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

unsigned char g_lvl_1[15][13] = {
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


unsigned char g_lvl_2[15][13] = {
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

unsigned char g_lvl_3[15][13] = {
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

void GameEngine::initSounds()
{
    m_brkcube = new QSound(":/sounds/hit_cube.wav");
    m_ubrkcube = new QSound(":/sounds/hit_unbreakable.wav");
    m_racket = new QSound(":/sounds/hit_racket.wav");
    m_lose = new QSound(":/sounds/lose.wav");
}

void GameEngine::initData(Border *p_lft, Border *p_top, Border *p_rght)
{
    m_lft = p_lft;
    m_top = p_top;
    m_rght = p_rght;
}

void GameEngine::playSound(sounds p)
{
    switch (p)
    {
    case hitbrk:
        m_brkcube->play();
        break;
    case hitubrk:
        m_ubrkcube->play();
        break;
    case hitracket:
        m_racket->play();
        break;
    case lose:
        m_lose->play();
        break;
    }
}

void GameEngine::startNewGame()
{
    m_player = new Racket(100,520);
    m_mtx = new CubeMatrix;
    m_ball = new Ball(100,400,qreal(1.0),qreal(10*M_PI/180));
    m_mtx->fillLevel(g_lvl_2);
    m_player->setFlag(QGraphicsItem::ItemIsFocusable);
    m_player->setFocus();
}

void GameEngine::cleanup()
{
    delete m_ball;
    delete m_player;
    delete m_mtx;

    m_ball = NULL;
    m_player = NULL;
    m_mtx = NULL;
}
