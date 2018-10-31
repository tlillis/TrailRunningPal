#include "athlwindow.h"
#include "ui_athlwindow.h"

AthlWindow::AthlWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AthlWindow)
{
    ui->setupUi(this);
}

AthlWindow::~AthlWindow()
{
    delete ui;
}
