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
#include <QSound>
#include <QGraphicsPixmapItem>

#include "cube.h"
#include "ball.h"
#include "racket.h"
#include "border.h"
#include "lives.h"
#include "score.h"

#define SCOREHEIGHT 60
#define LOOSELINE 550

enum blocks { empty, green, cyan, blue, yellow, red, ub };
enum sounds { hitbrk, hitubrk, hitracket, hitborder, lose, gameover};
enum border { borderleft, bordertop, borderright };

class Ball;
class Score;
class Lives;
class Racket;
class Border;
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
    Score *getScore() const;
    Lives *getLives() const;
    void initSounds();
    void initData(Border *,Border *,Border *);
    void playSound(sounds);
    void startNewGame();
    void cleanup();
    void remPlayer();
    void showGameWon();
    void showGameOver();

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
    Ball *m_ball;
    Racket *m_player;
    CubeMatrix *m_mtx;
    Border *m_lft,*m_top,*m_rght;
    Score *m_score;
    Lives *m_lives;
    QSound *m_brkcube,*m_ubrkcube,*m_racket,*m_lose,*m_border,*m_gameover;
    QGraphicsTextItem *m_gametxt;

    static GameEngine *s_instance;
    GameEngine(){}
};

#endif // GAME_H
