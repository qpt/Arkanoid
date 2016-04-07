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
#include "cube.h"

namespace Ui {
class MainWindow;
}

class Pixmap : public QObject, public QGraphicsPixmapItem, public QVariant {
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
    Q_PROPERTY(qreal opacity READ opacity WRITE setOpacity)
    Q_PROPERTY(qreal rotation READ rotation WRITE setRotation)

public:
    Pixmap(const QPixmap &pix): QObject(), QGraphicsPixmapItem(pix) {
        setCacheMode(DeviceCoordinateCache);
    }
    virtual void mousePressEvent(QGraphicsSceneMouseEvent * ) Q_DECL_OVERRIDE {
        emit clicked();
    }
Q_SIGNALS:
    void clicked();
};

class View : public QGraphicsView {
public:
    View(QGraphicsScene *scene) : QGraphicsView(scene) { }
protected:
    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE {
        QGraphicsView::resizeEvent(event);
        fitInView(sceneRect(), Qt::KeepAspectRatio);
    }
};


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
