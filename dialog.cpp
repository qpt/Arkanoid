/*
  Copyright (c) 2016 David Hovhannisyan

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License as
  published by the Free Software Foundation; either version 2 of the
  License, or (at your option) any later version.  See the file
  COPYING included with this distribution for more information.

*/

#include "dialog.h"
#include "ui_dialog.h"


Dialog::Dialog(QWidget *parent):QDialog(parent),m_ui(new Ui::Dialog)
{
    QPixmap q(":/img/Arkanoid_arcadeflyer.jpg");
    m_pic = new QLabel(this);
    m_info = new QLabel("Created with Qt Framework\n\nLicense: GPL v3\n\n (c) David Hovhannisyan");
    m_pic->setPixmap(q);
    m_oKay = new QPushButton("Ok");
    m_hlay0 = new QHBoxLayout;
    m_hlay0->addWidget(m_oKay);
    m_hlay0->setAlignment(m_oKay,Qt::AlignCenter);
    m_vlay = new QVBoxLayout;
    m_vlay->addWidget(m_info);
    m_vlay->setAlignment(m_info,Qt::AlignCenter);
    m_vlay->addLayout(m_hlay0);
    m_vlay2 = new QVBoxLayout;
    m_vlay2->addWidget(m_pic);
    m_hlay = new QHBoxLayout;
    m_hlay->addLayout(m_vlay2);
    m_hlay->addLayout(m_vlay);
    setLayout(m_hlay);
    connect(m_oKay,SIGNAL(clicked(bool)),this,SLOT(close()));
    m_ui->setupUi(this);
    setFixedSize(size());
    QIcon ico(tr(":/icon.ico"));
    setWindowIcon(ico);
}

Dialog::~Dialog()
{
    delete m_ui;
}
