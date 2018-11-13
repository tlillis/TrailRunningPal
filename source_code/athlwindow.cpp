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

void AthlWindow::import_runs(RunsDataContainer data)
{
    std::vector <RunData> runs = data.get_runs();
    std::cout << "Import runs: " << runs.size() << std::endl;
    for(unsigned int i = 0; i < runs.size(); i++)
    {
        ui->tableWidget->insertRow ( ui->tableWidget->rowCount() );
        ui->tableWidget->setItem   ( ui->tableWidget->rowCount()-1,
                                     0,
                                     new QTableWidgetItem(QString::fromStdString(runs[i].get_date())));
        ui->tableWidget->setItem   ( ui->tableWidget->rowCount()-1,
                                     1,
                                     new QTableWidgetItem(QString::fromStdString(runs[i].get_time())));
        ui->tableWidget->setItem   ( ui->tableWidget->rowCount()-1,
                                     2,
                                     new QTableWidgetItem(QString::fromStdString(runs[i].get_miles())));
        ui->tableWidget->setItem   ( ui->tableWidget->rowCount()-1,
                                     3,
                                     new QTableWidgetItem(QString::fromStdString(runs[i].get_egain())));
        ui->tableWidget->setItem   ( ui->tableWidget->rowCount()-1,
                                     4,
                                     new QTableWidgetItem(QString::fromStdString(runs[i].get_mhr())));
        ui->tableWidget->setItem   ( ui->tableWidget->rowCount()-1,
                                     5,
                                     new QTableWidgetItem(QString::fromStdString(runs[i].get_ahr())));
        ui->tableWidget->setItem   ( ui->tableWidget->rowCount()-1,
                                     6,
                                     new QTableWidgetItem(QString::fromStdString(runs[i].get_cals())));
        ui->tableWidget->setItem   ( ui->tableWidget->rowCount()-1,
                                     7,
                                     new QTableWidgetItem(QString::fromStdString(runs[i].get_fastest())));
        ui->tableWidget->setItem   ( ui->tableWidget->rowCount()-1,
                                     8,
                                     new QTableWidgetItem(QString::fromStdString(runs[i].get_tag())));
    }
}


AthlWindow::~AthlWindow()
{
    delete ui;
}
