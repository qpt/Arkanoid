/*
  Copyright (c) 2016 David Hovhannisyan

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License as
  published by the Free Software Foundation; either version 2 of the
  License, or (at your option) any later version.  See the file
  LICENSE included with this distribution for more information.

*/

#ifndef CUBE_H
#define CUBE_H

#include <QGraphicsRectItem>
#include <QStack>
#include "game.h"

#define CUBESWIDTH 32
#define CUBESHEIGHT 16
#define WSTART 6*2
#define HSTART SCOREHEIGHT + 7*2 + 40

class Cube: public QObject, public QGraphicsRectItem {
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    Cube(bool brk,Qt::GlobalColor clr,int hlth,int posx, int posy, int w, int h);
    void removeFromScene();
    virtual void actingOnCollision()=0;
    virtual ~Cube();
protected:
    QRect *m_rect;
    bool m_breakability;
    int m_health;
    bool deleted;
};

class RedCube: public Cube {
public:
    RedCube(int posx, int posy, int w=CUBESWIDTH, int h=CUBESHEIGHT):Cube(true,Qt::red,4,posx,posy,w,h) {}
    void actingOnCollision();
private:
};

class YellowCube: public Cube {
public:
    YellowCube(int posx, int posy, int w=CUBESWIDTH, int h=CUBESHEIGHT):Cube(true,Qt::yellow,3,posx,posy,w,h) {}
    void actingOnCollision();
private:
};

class BlueCube: public Cube {
public:
    BlueCube(int posx, int posy, int w=CUBESWIDTH, int h=CUBESHEIGHT):Cube(true,Qt::blue,2,posx,posy,w,h) {}
    void actingOnCollision();
private:
};

class CyanCube: public Cube {
public:
    CyanCube(int posx, int posy, int w=CUBESWIDTH, int h=CUBESHEIGHT):Cube(true,Qt::cyan,1,posx,posy,w,h) {}
    void actingOnCollision();
private:
};

class GreenCube: public Cube {
public:
    GreenCube(int posx, int posy, int w=CUBESWIDTH, int h=CUBESHEIGHT):Cube(true,Qt::green,0,posx,posy,w,h) {}
    void actingOnCollision();
private:
};

class UnbreakableCube: public Cube {
public:
    UnbreakableCube(int posx, int posy, int w=CUBESWIDTH, int h=CUBESHEIGHT):Cube(false,Qt::gray,0,posx,posy,w,h) {}
    void actingOnCollision();
private:
};

class CubeMatrix {
public:
    CubeMatrix():cubes(new QStack<Cube*>){}
    void fillLevel(unsigned char M[15][13],int n=15,int m=13);
    ~CubeMatrix();
private:
    QStack<Cube*> *cubes;
};

#endif // CUBE_H
