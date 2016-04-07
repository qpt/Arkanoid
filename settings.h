/*
  Copyright (c) 2016 David Hovhannisyan

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License as
  published by the Free Software Foundation; either version 2 of the
  License, or (at your option) any later version.  See the file
  COPYING included with this distribution for more information.

*/

#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QLabel>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT
public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();
private:
    QLabel *m_info,*m_info2;
    QLineEdit *m_nameField,*m_cpunameField;
    QPushButton *m_save,*m_discard;
    QHBoxLayout *m_hlay,*m_hlay0;
    QVBoxLayout *m_vlay,*m_vlay2;
    Ui::Settings *ui;
public slots:
    void save();
};

#endif // SETTINGS_H
