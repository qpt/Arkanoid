/*
  Copyright (c) 2016 David Hovhannisyan

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License as
  published by the Free Software Foundation; either version 2 of the
  License, or (at your option) any later version.  See the file
  LICENSE included with this distribution for more information.

*/

#include "score.h"

Score::Score(QGraphicsItem* parent): QGraphicsTextItem(parent)
{
    m_score = 0;
    setPlainText(QString::number(m_score) + QString("  SCORE"));
    setDefaultTextColor(Qt::white);
    setFont(QFont("terminal",16));
    setPos(50,30);
    GameEngine::instance()->getScene()->addItem(this);
}

void Score::increase(int x)
{
    m_score+=x;
    setPlainText(QString::number(m_score) + QString("  SCORE"));
    setDefaultTextColor(Qt::white);
    setFont(QFont("terminal",16));
}

void Score::updateScore()
{

}

int Score::getScore()
{
    return m_score;
}

Score::~Score()
{
    GameEngine::instance()->getScene()->removeItem(this);
}
