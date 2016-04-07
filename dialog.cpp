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


Dialog::Dialog(QWidget *parent):QDialog(parent),m_ui(new Ui::Dialog) {
    m_pic = new QLabel(this);
    QPixmap q(":/img/about.jpg");
    m_pic->setPixmap(q);
    m_pic->show();

    m_info = new QLabel(tr("This program is written in Qt under GPL\n Copyright (c) David Hovhannisyan 2016"),this);
    m_info->setGeometry(0,75,360,100);
    m_info->setStyleSheet(tr("QLabel { font-family: Tahoma; font-style: bold,oblique; font-size: 20px;  }"));
    m_info->show();

    m_cool = new QPushButton(tr("&Cool"),this);
    m_cool->setGeometry(365,110,30,30);
    m_cool->show();

    connect(m_cool,SIGNAL(clicked()),SLOT(close()));

    setWindowFlags(Qt::SplashScreen);
    m_ui->setupUi(this);
}

Dialog::~Dialog() {
    delete m_ui;
}
