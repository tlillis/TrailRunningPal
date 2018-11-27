#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    Login* login = NULL;
    if (login_type == "athelete") {
        login = new AthleteLogin();
    }
    else if(login_type == "coach") {
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
    login_type = "athelete";
}

void MainWindow::on_radioButton_coach_clicked()
{
    login_type = "coach";
}
