/*
  Copyright (c) 2016 David Hovhannisyan

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License as
  published by the Free Software Foundation; either version 2 of the
  License, or (at your option) any later version.  See the file
  LICENSE included with this distribution for more information.

*/

#include "ball.h"
#include <QDebug>

Ball::Ball(int posx, int posy,qreal v,qreal phi, QGraphicsItem *parent):
    QObject(),QGraphicsPixmapItem(parent)
{
    m_velocity = v;
    m_angle = phi;
    QPixmap pix(":/img/ball.png");
    pix = pix.scaled(pix.width()*2,pix.height()*2, Qt::KeepAspectRatio, Qt::FastTransformation);
    setPixmap(pix);
    setPos(posx,posy);
    GameEngine::instance()->getScene()->addItem(this);
    m_timer = new QTimer;
    connect(m_timer,SIGNAL(timeout()),this,SLOT(move()));
    m_timer->start(10);
}

void Ball::changeDirection(qreal phi)
{
    m_angle = phi;
}

void Ball::changeSpeed(qreal v)
{
    m_velocity = v;
}

Ball::~Ball()
{
    GameEngine::instance()->getScene()->removeItem(this);
}

void Ball::move()
{
    setPos(x()+ m_velocity * qCos(m_angle),y() + m_velocity * qSin(m_angle));
    if(y() > LOOSELINE)
    {
        GameEngine::instance()->playSound(lose);
        GameEngine::instance()->remPlayer();
    }
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i )
    {
        if(Cube* curr = dynamic_cast<Cube*>(colliding_items[i]))
        {
            changeDirection(m_angle - M_PI);
            curr->actingOnCollision();
            break;
        }
        if(Racket* curr = dynamic_cast<Racket*>(colliding_items[i]))
        {
            GameEngine::instance()->playSound(hitracket);
            changeDirection(-m_angle + 2*M_PI);
            break;
        }
        if(Border* curr = dynamic_cast<Border*>(colliding_items[i]))
        {
            GameEngine::instance()->playSound(hitborder);
            switch(curr->getType())
            {
            case borderleft:
                changeDirection(-m_angle - M_PI);
                break;
            case bordertop:
                changeDirection(2*M_PI - m_angle);
                break;
            case borderright:
                changeDirection(M_PI - m_angle);
                break;
            }
            break;
        }
    }
}
