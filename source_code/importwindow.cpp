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
        std::ofstream outfile;
        outfile.open ("output.txt");
        outfile << "Route\t" << route.toStdString() << "\n";
        outfile << "Time\t" << time.toStdString() << "\n";
        outfile << "Miles\t" << miles.toStdString() << "\n";
        outfile << "EGain\t" << egain.toStdString() << "\n";
        outfile << "MHR\t" << mhr.toStdString() << "\n";
        outfile << "AHR\t" << avr.toStdString() << "\n";
        outfile << "Cals\t" << cals.toStdString() << "\n";
        outfile << "Fastest\t" << fastest.toStdString() << "\n";
        outfile << "Tags\t" << tags.toStdString() << "\n";
        outfile.close();
        QMessageBox::information(this, "Imported", "Imported Run Saved");
        this->close();
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
