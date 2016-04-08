/*
  Copyright (c) 2016 David Hovhannisyan

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License as
  published by the Free Software Foundation; either version 2 of the
  License, or (at your option) any later version.  See the file
  LICENSE included with this distribution for more information.

*/

#include "cube.h"

Cube::Cube(bool brk,Qt::GlobalColor clr,int hlth,int posx, int posy, int w, int h):
    m_breakability(brk), m_health(hlth)
{
    setRect(0,0,w,h);
    setPos(posx,posy);
    setBrush(QBrush(clr));
    GameEngine::instance()->getScene()->addItem(this);
}

Cube::~Cube()
{
    GameEngine::instance()->getScene()->removeItem(this);
}


void CubeMatrix::fillLevel(int M[15][13],int n,int m)
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
                cubes->push(new GreenCube(c_wstart+j*cubesWidth,c_hstart+cubesHeight*i));
                break;
            case cyan:
                cubes->push(new CyanCube(c_wstart+j*cubesWidth,c_hstart+cubesHeight*i));
                break;
            case blue:
                cubes->push(new BlueCube(c_wstart+j*cubesWidth,c_hstart+cubesHeight*i));
                break;
            case yellow:
                cubes->push(new YellowCube(c_wstart+j*cubesWidth,c_hstart+cubesHeight*i));
                break;
            case red:
                cubes->push(new RedCube(c_wstart+j*cubesWidth,c_hstart+cubesHeight*i));
                break;
            case ub:
                cubes->push(new UnbreakableCube(c_wstart+j*cubesWidth,c_hstart+cubesHeight*i));
                break;
            }
        }
    }
}

CubeMatrix::~CubeMatrix()
{
    while(cubes->empty()) {
        delete cubes->top();
        cubes->pop();
    }
}
