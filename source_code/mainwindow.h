#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "athlwindow.h"
#include "coachwindow.h"
#include "ui_mainwindow.h"
#include "login.h"

#include <iostream>

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_Login_clicked();
    void on_radioButton_athelete_clicked();
    void on_radioButton_coach_clicked();

private:
    QString _loginType;
    Ui::MainWindow *_ui;
};

#endif // MAINWINDOW_H
