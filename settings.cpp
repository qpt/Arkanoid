/*
  Copyright (c) 2016 David Hovhannisyan

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License as
  published by the Free Software Foundation; either version 2 of the
  License, or (at your option) any later version.  See the file
  COPYING included with this distribution for more information.

*/

#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    m_info = new QLabel("Change your name:");
    m_info2 = new QLabel("Change CPU player name:");
    m_save = new QPushButton("Save");
    m_discard = new QPushButton("Discard");
    m_hlay0 = new QHBoxLayout;
    m_hlay0->addWidget(m_save);
    m_hlay0->addWidget(m_discard);
    m_vlay = new QVBoxLayout;
    m_vlay->addWidget(m_info);
    //m_vlay->addWidget(m_nameField);
    m_vlay->addWidget(m_info2);
    //m_vlay->addWidget(m_cpunameField);
    m_vlay->addLayout(m_hlay0);
    m_hlay = new QHBoxLayout;
    m_hlay->addLayout(m_vlay);
    setLayout(m_hlay);
    connect(m_save,SIGNAL(clicked(bool)),this,SLOT(save()));
    connect(m_discard,SIGNAL(clicked(bool)),this,SLOT(close()));
    ui->setupUi(this);
    setFixedSize(size());
}

Settings::~Settings()
{
    delete ui;
}

void Settings::save() {
    close();
}
