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

#include "cube.h"
#include "ball.h"
#include "racket.h"
#include "lives.h"
#include "score.h"

enum blocks { empty, green, cyan, blue, yellow, red, ub };

class Ball;
class Racket;
class CubeMatrix;

class Pixmap : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
    Q_PROPERTY(qreal opacity READ opacity WRITE setOpacity)
    Q_PROPERTY(qreal rotation READ rotation WRITE setRotation)
public:
    Pixmap(const QPixmap &pix): QObject(), QGraphicsPixmapItem(pix) {
        setCacheMode(DeviceCoordinateCache);
    }
};

class GameEngine {
public:
    void setScene(QGraphicsScene* );
    QGraphicsScene* getScene() const;
    void startNewGame();
    void cleanup();

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
    Ball *ball;
    Racket *player;
    CubeMatrix *mtx;

    static GameEngine *s_instance;
    GameEngine(){}
};

#endif // GAME_H
