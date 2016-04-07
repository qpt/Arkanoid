/*
  Copyright (c) 2016 David Hovhannisyan

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License as
  published by the Free Software Foundation; either version 2 of the
  License, or (at your option) any later version.  See the file
  LICENSE included with this distribution for more information.

*/

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(800,600);
    m_file = menuBar()->addMenu("Game");
    m_help = menuBar()->addMenu("Help");
    m_newGame = new QAction(tr("&New Game"),this);
    m_settings = new QAction(tr("&Settings"),this);
    m_exit = new QAction(tr("E&xit"),this);
    m_about = new QAction(tr("About Durak"),this);
    m_newGame->setShortcut(QKeySequence::New);
    m_newGame->setShortcut(QKeySequence::Close);

    connect(m_newGame,SIGNAL(triggered()),this,SLOT(startNewGame()));
    connect(m_settings,SIGNAL(triggered()),this,SLOT(openSettings()));
    connect(m_exit,SIGNAL(triggered()),this,SLOT(close()));
    connect(m_about,SIGNAL(triggered()),this,SLOT(openAbout()));

    m_file->addAction(m_newGame);
    m_file->addSeparator();
    m_file->addAction(m_settings);
    m_file->addSeparator();
    m_file->addAction(m_exit);
    m_help->addAction(m_about);
}

void MainWindow::startNewGame() {

}

void MainWindow::openSettings()
{
    m_setDlg = new Settings(this);
    m_setDlg->setWindowTitle("Settings");
    m_setDlg->show();
}

void MainWindow::openAbout()
{
    m_aboutDlg = new Dialog(this);
    m_aboutDlg->show();
}


MainWindow::~MainWindow()
{
    delete ui;
}
