/*
  Copyright (c) 2016 David Hovhannisyan

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License as
  published by the Free Software Foundation; either version 2 of the
  License, or (at your option) any later version.  See the file
  LICENSE included with this distribution for more information.

*/

#include "lives.h"

Lives::Lives(QGraphicsItem* parent): QGraphicsTextItem(parent)
{
    m_lives = 3;
    setPlainText(QString::number(m_lives) + QString(" UP"));
    setDefaultTextColor(Qt::red);
    setFont(QFont("terminal",16));
    setPos(50,0);
    GameEngine::instance()->getScene()->addItem(this);
}

Lives::~Lives()
{
    GameEngine::instance()->getScene()->removeItem(this);
}

void Lives::decrease()
{
    --m_lives;
    setPlainText(QString::number(m_lives) + QString(" UP"));
    setDefaultTextColor(Qt::red);
    setFont(QFont("terminal",16));
}

int Lives::getLives()
{
    return m_lives;
}
