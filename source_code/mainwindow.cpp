#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

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

    if(username ==  "test" && password == "test") {
        //
        //hide();
        if (login_type == "athelete") {
            AthlWindow *athelete_window = new AthlWindow();
            athelete_window->show();
        }
        else if(login_type == "coach") {
            CoachWindow *coach_window = new CoachWindow();
            coach_window->show();
        }
        else {
            QMessageBox::information(this, "Login", "Must select either athelete or coach");
        }
    }
    else {
        QMessageBox::warning(this,"Login", "Username and password is not correct");
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
