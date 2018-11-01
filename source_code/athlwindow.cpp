#include "athlwindow.h"
#include "ui_athlwindow.h"

#include <QMessageBox>

AthlWindow::AthlWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AthlWindow)
{
    ui->setupUi(this);
}

void AthlWindow::on_pushButton_Import_clicked()
{
    ImportWindow *import_window = new ImportWindow();
    import_window->show();
}

AthlWindow::~AthlWindow()
{
    delete ui;
}
