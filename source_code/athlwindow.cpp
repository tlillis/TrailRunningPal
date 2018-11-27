#include "athlwindow.h"
#include "ui_athlwindow.h"

AthlWindow::AthlWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AthlWindow)
{
    ui->setupUi(this);
}

void AthlWindow::on_pushButton_Import_clicked()
{
    AthleteObserver *obs = new AthleteObserver();
    obs->use_window(this);

    FileUpdater *updater = new FileUpdater();
    updater->attach(obs);

    ImportWindow *import_window = new ImportWindow();
    import_window->use_observer(updater);
    import_window->show();
}

void AthlWindow::import_athlete(AthleteDataContainer data)
{
    ui->miles->setText(QString::fromStdString(data.get_miles()));
    ui->ytd_miles->setText(QString::fromStdString(data.get_ytd_miles()));
    ui->last_miles->setText(QString::fromStdString(data.get_last_miles()));
    ui->pace->setText(QString::fromStdString(data.get_pace()));
    ui->ytd_pace->setText(QString::fromStdString(data.get_ytd_pace()));
    ui->ascent->setText(QString::fromStdString(data.get_ascent()));
    ui->ytd_ascent->setText(QString::fromStdString(data.get_ytd_ascent()));
    ui->mile1->setText(QString::fromStdString(data.get_mile1()));
    ui->mile2->setText(QString::fromStdString(data.get_mile2()));
    ui->k5->setText(QString::fromStdString(data.get_k5()));
    ui->k10->setText(QString::fromStdString(data.get_k10()));
    ui->half_mar->setText(QString::fromStdString(data.get_half_mar()));
    ui->mar->setText(QString::fromStdString(data.get_mar()));
    ui->mile50->setText(QString::fromStdString(data.get_mile50()));
}

void AthlWindow::import_runs(RunsDataContainer data)
{
    std::vector <RunDataContainer> runs = data.get_runs();
    std::cout << "Import runs: " << runs.size() << std::endl;
    ui->tableWidget->setRowCount(0);
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
