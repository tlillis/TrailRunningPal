#include "athlwindow.h"
#include "ui_athlwindow.h"

AthlWindow::AthlWindow(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::AthlWindow)
{
    _ui->setupUi(this);
}

void AthlWindow::setUser(std::string username)
{
    _user = username;
    _ui->welcome->setText(QString::fromStdString("Welcome " + _user));
}

void AthlWindow::on_pushButton_Import_clicked()
{
    AthleteObserver *obs = new AthleteObserver();
    obs->setWindow(this);

    FileUpdater *updater = new FileUpdater();
    updater->attach(obs);

    ImportWindow *importWindow = new ImportWindow();
    importWindow->setObserver(updater);
    importWindow->setUser(_user);
    importWindow->show();
}

void AthlWindow::importAthlete(AthleteDataContainer data)
{
    _ui->miles->setText(QString::fromStdString(data.getMiles()));
    _ui->ytd_miles->setText(QString::fromStdString(data.getYtdMiles()));
    _ui->last_miles->setText(QString::fromStdString(data.getLastMiles()));
    _ui->pace->setText(QString::fromStdString(data.getPace()));
    _ui->ytd_pace->setText(QString::fromStdString(data.getYtdPace()));
    _ui->ascent->setText(QString::fromStdString(data.getAscent()));
    _ui->ytd_ascent->setText(QString::fromStdString(data.getYtdAscent()));
    _ui->mile1->setText(QString::fromStdString(data.getMile1()));
    _ui->mile2->setText(QString::fromStdString(data.getMile2()));
    _ui->k5->setText(QString::fromStdString(data.getK5()));
    _ui->k10->setText(QString::fromStdString(data.getK10()));
    _ui->half_mar->setText(QString::fromStdString(data.getHalfMar()));
    _ui->mar->setText(QString::fromStdString(data.getMar()));
    _ui->mile50->setText(QString::fromStdString(data.getMile50()));
}

void AthlWindow::importRuns(RunsDataContainer data)
{
    std::vector <RunDataContainer> runs = data.getRuns();
    std::cout << "Import runs: " << runs.size() << std::endl;
    _ui->tableWidget->setRowCount(0);
    for(unsigned int i = 0; i < runs.size(); i++)
    {
        _ui->tableWidget->insertRow ( _ui->tableWidget->rowCount() );
        _ui->tableWidget->setItem   ( _ui->tableWidget->rowCount()-1,
                                     0,
                                     new QTableWidgetItem(QString::fromStdString(runs[i].getDate())));
        _ui->tableWidget->setItem   ( _ui->tableWidget->rowCount()-1,
                                     1,
                                     new QTableWidgetItem(QString::fromStdString(runs[i].getTime())));
        _ui->tableWidget->setItem   ( _ui->tableWidget->rowCount()-1,
                                     2,
                                     new QTableWidgetItem(QString::fromStdString(runs[i].getMiles())));
        _ui->tableWidget->setItem   ( _ui->tableWidget->rowCount()-1,
                                     3,
                                     new QTableWidgetItem(QString::fromStdString(runs[i].getEgain())));
        _ui->tableWidget->setItem   ( _ui->tableWidget->rowCount()-1,
                                     4,
                                     new QTableWidgetItem(QString::fromStdString(runs[i].getMhr())));
        _ui->tableWidget->setItem   ( _ui->tableWidget->rowCount()-1,
                                     5,
                                     new QTableWidgetItem(QString::fromStdString(runs[i].getAhr())));
        _ui->tableWidget->setItem   ( _ui->tableWidget->rowCount()-1,
                                     6,
                                     new QTableWidgetItem(QString::fromStdString(runs[i].getCals())));
        _ui->tableWidget->setItem   ( _ui->tableWidget->rowCount()-1,
                                     7,
                                     new QTableWidgetItem(QString::fromStdString(runs[i].getFastest())));
        _ui->tableWidget->setItem   ( _ui->tableWidget->rowCount()-1,
                                     8,
                                     new QTableWidgetItem(QString::fromStdString(runs[i].getTag())));
    }

}


AthlWindow::~AthlWindow()
{
    delete _ui;
}
