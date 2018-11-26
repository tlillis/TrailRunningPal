#include "importwindow.h"
#include "ui_importwindow.h"

#include <iostream>
#include <fstream>

#include <QMessageBox>

ImportWindow::ImportWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImportWindow)
{
    ui->setupUi(this);
}

void ImportWindow::use_observer(FileUpdater *updater)
{
    _updater = updater;
}

void ImportWindow::on_pushButton_Import_clicked()
{
    QString route = ui->lineEdit_Route->text();
    QString time = ui->lineEdit_Time->text();
    QString avr = ui->lineEdit_AVR->text();
    QString cals = ui->lineEdit_Cals->text();
    QString mhr = ui->lineEdit_MHR->text();
    QString miles = ui->lineEdit_Miles->text();
    QString egain = ui->lineEdit_EGain->text();
    QString fastest = ui->lineEdit_Fastest->text();
    QString tags = ui->lineEdit_Tags->text();

    if(route != "" && time != "")
    {
        if(_updater != NULL)
        {
            std::string data = "11/24/18,";
            data += time.toStdString() + ",";
            data += miles.toStdString() + ",";
            data += egain.toStdString() + ",";
            data += mhr.toStdString() + ",";
            data += avr.toStdString() + ",";
            data += cals.toStdString() + ",";
            data += fastest.toStdString() + ",";
            data += tags.toStdString() + "\n";

            _updater->write("tom","runs.csv",data);
            _updater->notify(username);
            QMessageBox::information(this, "Imported", "Imported Run Saved");
            this->close();
        }
    }
    else
    {
        QMessageBox::information(this, "Import Failed", "Must input at least route and time");
    }
}

ImportWindow::~ImportWindow()
{
    delete ui;
}
