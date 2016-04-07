/*
  Copyright (c) 2016 David Hovhannisyan

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License as
  published by the Free Software Foundation; either version 2 of the
  License, or (at your option) any later version.  See the file
  LICENSE included with this distribution for more information.

*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QMenuBar>
#include <QVariant>
#include <QMenu>
#include <QAction>
#include "dialog.h"
#include "settings.h"
#include "game.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *m_scene;

    QMenu *m_file,*m_help;
    QAction *m_newGame,*m_settings,*m_exit,*m_about;
    Dialog *m_aboutDlg;
    Settings *m_setDlg;
private slots:
    void openAbout();
    void openSettings();
    void startNewGame();
};

#endif // MAINWINDOW_H
