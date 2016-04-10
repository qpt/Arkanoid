/*
  Copyright (c) 2016 David Hovhannisyan

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License as
  published by the Free Software Foundation; either version 2 of the
  License, or (at your option) any later version.  See the file
  LICENSE included with this distribution for more information.

*/

#include "cube.h"

Cube::Cube(Qt::GlobalColor clr,int posx, int posy, int w, int h):
    deleted(false)
{
    setRect(0,0,w,h);
    setPos(posx,posy);
    setBrush(QBrush(clr));
    GameEngine::instance()->getScene()->addItem(this);
}

void Cube::removeFromScene()
{
    if(!deleted)
    {
        GameEngine::instance()->getScene()->removeItem(this);
        deleted = true;
    }
}

Cube::~Cube()
{
    removeFromScene();
}

void BreakableCube::actingOnCollision()
{
    GameEngine::instance()->playSound(hitbrk);
    GameEngine::instance()->getScore()->increase();
    if(!m_health)
    {
        GameEngine::instance()->getScore()->updateScore();
        removeFromScene();
    }
    --m_health;
}

void UnbreakableCube::actingOnCollision()
{
    GameEngine::instance()->playSound(hitubrk);
}

void CubeMatrix::fillLevel(unsigned char M[15][13],int n,int m)
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            switch(M[i][j])
            {
            case empty:
                break;
            case green:
                cubes->push(new GreenCube(WSTART+j*CUBESWIDTH,HSTART+CUBESHEIGHT*i));
                break;
            case cyan:
                cubes->push(new CyanCube(WSTART+j*CUBESWIDTH,HSTART+CUBESHEIGHT*i));
                break;
            case blue:
                cubes->push(new BlueCube(WSTART+j*CUBESWIDTH,HSTART+CUBESHEIGHT*i));
                break;
            case yellow:
                cubes->push(new YellowCube(WSTART+j*CUBESWIDTH,HSTART+CUBESHEIGHT*i));
                break;
            case red:
                cubes->push(new RedCube(WSTART+j*CUBESWIDTH,HSTART+CUBESHEIGHT*i));
                break;
            case ub:
                cubes->push(new UnbreakableCube(WSTART+j*CUBESWIDTH,HSTART+CUBESHEIGHT*i));
                break;
            }
        }
    }
}

CubeMatrix::~CubeMatrix()
{
    while(!cubes->empty()) {
        delete cubes->top();
        cubes->pop();
    }
    delete cubes;
    cubes = NULL;
}
