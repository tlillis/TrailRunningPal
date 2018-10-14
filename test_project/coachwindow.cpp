#include "coachwindow.h"
#include "ui_coachwindow.h"

CoachWindow::CoachWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CoachWindow)
{
    ui->setupUi(this);
}

CoachWindow::~CoachWindow()
{
    delete ui;
}
