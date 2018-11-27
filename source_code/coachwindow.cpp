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

void CoachWindow::on_athleteButton_clicked()
{
    CoachObserver *obs = new CoachObserver();
    obs->use_window(this);

    FileUpdater *updater = new FileUpdater();
    updater->attach(obs);

    AddAthlete *add_athlete = new AddAthlete();
    add_athlete->use_observer(updater);
    add_athlete->show();
}

void CoachWindow::on_teamButton_clicked()
{
    CoachObserver *obs = new CoachObserver();
    obs->use_window(this);

    FileUpdater *updater = new FileUpdater();
    updater->attach(obs);

    AddTeam *add_team = new AddTeam();
    add_team->use_observer(updater);
    add_team->show();
}

void CoachWindow::on_ateamButton_clicked()
{
    CoachObserver *obs = new CoachObserver();
    obs->use_window(this);

    FileUpdater *updater = new FileUpdater();
    updater->attach(obs);

    AddTeamAthlete *add_ateam = new AddTeamAthlete();
    add_ateam->use_observer(updater);
    add_ateam->show();
}

void CoachWindow::import_athletes(AthletesDataContainer data)
{
    std::vector <AthleteDataContainer> athletes = data.get_athletes();
    std::cout << "Import athletes: " << athletes.size() << std::endl;
    ui->coachTable->setRowCount(0);
    for(unsigned int i = 0; i < athletes.size(); i++)
    {
        ui->coachTable->insertRow ( ui->coachTable->rowCount() );
        ui->coachTable->setItem   ( ui->coachTable->rowCount()-1,
                                     0,
                                     new QTableWidgetItem(QString::fromStdString(athletes[i].get_name())));
        ui->coachTable->setItem   ( ui->coachTable->rowCount()-1,
                                     1,
                                     new QTableWidgetItem(QString::fromStdString(athletes[i].get_miles())));
        ui->coachTable->setItem   ( ui->coachTable->rowCount()-1,
                                     2,
                                     new QTableWidgetItem(QString::fromStdString(athletes[i].get_pace())));
        ui->coachTable->setItem   ( ui->coachTable->rowCount()-1,
                                     3,
                                     new QTableWidgetItem(QString::fromStdString(athletes[i].get_ascent())));
        ui->coachTable->setItem   ( ui->coachTable->rowCount()-1,
                                     4,
                                     new QTableWidgetItem(QString::fromStdString(athletes[i].get_mile1())));
        ui->coachTable->setItem   ( ui->coachTable->rowCount()-1,
                                     5,
                                     new QTableWidgetItem(QString::fromStdString(athletes[i].get_k5())));
        ui->coachTable->setItem   ( ui->coachTable->rowCount()-1,
                                     6,
                                     new QTableWidgetItem(QString::fromStdString(athletes[i].get_k10())));
        ui->coachTable->setItem   ( ui->coachTable->rowCount()-1,
                                     7,
                                     new QTableWidgetItem(QString::fromStdString(athletes[i].get_half_mar())));
        ui->coachTable->setItem   ( ui->coachTable->rowCount()-1,
                                     8,
                                     new QTableWidgetItem(QString::fromStdString(athletes[i].get_mar())));
    }
}

void CoachWindow::import_teams(TeamsDataContainer data)
{
    std::vector <TeamDataContainer> teams = data.get_teams();
    std::cout << "Import teams: " << teams.size() << std::endl;
    ui->teamTable->setRowCount(0);
    for(unsigned int i = 0; i < teams.size(); i++)
    {
        ui->teamTable->insertRow ( ui->teamTable->rowCount() );
        ui->teamTable->setItem   ( ui->teamTable->rowCount()-1,
                                     0,
                                     new QTableWidgetItem(QString::fromStdString(teams[i].get_name())));
        ui->teamTable->setItem   ( ui->teamTable->rowCount()-1,
                                     1,
                                     new QTableWidgetItem(QString::fromStdString(teams[i].get_athletes())));
        ui->teamTable->setItem   ( ui->teamTable->rowCount()-1,
                                     2,
                                     new QTableWidgetItem(QString::fromStdString(teams[i].get_miles())));
        ui->teamTable->setItem   ( ui->teamTable->rowCount()-1,
                                     3,
                                     new QTableWidgetItem(QString::fromStdString(teams[i].get_pace())));
        ui->teamTable->setItem   ( ui->teamTable->rowCount()-1,
                                     4,
                                     new QTableWidgetItem(QString::fromStdString(teams[i].get_ascent())));
        ui->teamTable->setItem   ( ui->teamTable->rowCount()-1,
                                     5,
                                     new QTableWidgetItem(QString::fromStdString(teams[i].get_fastest())));
    }
}

