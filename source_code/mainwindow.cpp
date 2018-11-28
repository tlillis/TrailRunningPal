#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete _ui;
}

void MainWindow::on_pushButton_Login_clicked()
{
    QString username = _ui->lineEdit_username->text();
    QString password = _ui->lineEdit_password->text();

    Login* login = NULL;
    if (_loginType == "athelete") {
        login = new AthleteLogin();
    }
    else if(_loginType == "coach") {
        login = new CoachLogin();
    }
    else {
        QMessageBox::information(this, "Login", "Must select either athelete or coach");
        return;
    }
    if(login->login(username.toStdString(),password.toStdString()) == -1)
    {
        QMessageBox::information(this, "Login", "Incorrect credentials");
    }
}

void MainWindow::on_radioButton_athelete_clicked()
{
    _loginType = "athelete";
}

void MainWindow::on_radioButton_coach_clicked()
{
    _loginType = "coach";
}
