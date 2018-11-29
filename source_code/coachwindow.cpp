#include "coachwindow.h"
#include "ui_coachwindow.h"

CoachWindow::CoachWindow(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::CoachWindow)
{
    _ui->setupUi(this);
}

CoachWindow::~CoachWindow()
{
    delete _ui;
}

void CoachWindow::setUser(std::string username)
{
    _user = username;
    _ui->welcome->setText(QString::fromStdString("Welcome Coach " + _user));
}


void CoachWindow::on_athleteButton_clicked()
{
    CoachObserver *obs = new CoachObserver();
    obs->setWindow(this);

    FileUpdater *updater = new FileUpdater();
    updater->attach(obs);

    AddAthlete *addAthlete = new AddAthlete();
    addAthlete->setObserver(updater);
    addAthlete->setUser(_user);
    addAthlete->show();
}

void CoachWindow::on_teamButton_clicked()
{
    CoachObserver *obs = new CoachObserver();
    obs->setWindow(this);

    FileUpdater *updater = new FileUpdater();
    updater->attach(obs);

    AddTeam *addTeam = new AddTeam();
    addTeam->setObserver(updater);
    addTeam->setUser(_user);
    addTeam->show();
}

void CoachWindow::on_ateamButton_clicked()
{
    CoachObserver *obs = new CoachObserver();
    obs->setWindow(this);

    FileUpdater *updater = new FileUpdater();
    updater->attach(obs);

    AddTeamAthlete *addTeamAthl = new AddTeamAthlete();
    addTeamAthl->setObserver(updater);
    addTeamAthl->setUser(_user);
    addTeamAthl->show();
}

void CoachWindow::importAthletes(AthletesDataContainer data)
{
    std::vector <AthleteDataContainer> athletes = data.getAthletes();
    std::cout << "Import athletes: " << athletes.size() << std::endl;
    _ui->coachTable->setRowCount(0);
    for(unsigned int i = 0; i < athletes.size(); i++)
    {
        _ui->coachTable->insertRow ( _ui->coachTable->rowCount() );
        _ui->coachTable->setItem   ( _ui->coachTable->rowCount()-1,
                                     0,
                                     new QTableWidgetItem(QString::fromStdString(athletes[i].getName())));
        _ui->coachTable->setItem   ( _ui->coachTable->rowCount()-1,
                                     1,
                                     new QTableWidgetItem(QString::fromStdString(athletes[i].getMiles())));
        _ui->coachTable->setItem   ( _ui->coachTable->rowCount()-1,
                                     2,
                                     new QTableWidgetItem(QString::fromStdString(athletes[i].getPace())));
        _ui->coachTable->setItem   ( _ui->coachTable->rowCount()-1,
                                     3,
                                     new QTableWidgetItem(QString::fromStdString(athletes[i].getAscent())));
        _ui->coachTable->setItem   ( _ui->coachTable->rowCount()-1,
                                     4,
                                     new QTableWidgetItem(QString::fromStdString(athletes[i].getMile1())));
        _ui->coachTable->setItem   ( _ui->coachTable->rowCount()-1,
                                     5,
                                     new QTableWidgetItem(QString::fromStdString(athletes[i].getK5())));
        _ui->coachTable->setItem   ( _ui->coachTable->rowCount()-1,
                                     6,
                                     new QTableWidgetItem(QString::fromStdString(athletes[i].getK10())));
        _ui->coachTable->setItem   ( _ui->coachTable->rowCount()-1,
                                     7,
                                     new QTableWidgetItem(QString::fromStdString(athletes[i].getHalfMar())));
        _ui->coachTable->setItem   ( _ui->coachTable->rowCount()-1,
                                     8,
                                     new QTableWidgetItem(QString::fromStdString(athletes[i].getMar())));
    }
}

void CoachWindow::importTeams(TeamsDataContainer data)
{
    std::vector <TeamDataContainer> teams = data.getTeams();
    std::cout << "Import teams: " << teams.size() << std::endl;
    _ui->teamTable->setRowCount(0);
    for(unsigned int i = 0; i < teams.size(); i++)
    {
        _ui->teamTable->insertRow ( _ui->teamTable->rowCount() );
        _ui->teamTable->setItem   ( _ui->teamTable->rowCount()-1,
                                     0,
                                     new QTableWidgetItem(QString::fromStdString(teams[i].getName())));
        _ui->teamTable->setItem   ( _ui->teamTable->rowCount()-1,
                                     1,
                                     new QTableWidgetItem(QString::fromStdString(teams[i].getAthletes())));
        _ui->teamTable->setItem   ( _ui->teamTable->rowCount()-1,
                                     2,
                                     new QTableWidgetItem(QString::fromStdString(teams[i].getMiles())));
        _ui->teamTable->setItem   ( _ui->teamTable->rowCount()-1,
                                     3,
                                     new QTableWidgetItem(QString::fromStdString(teams[i].getPace())));
        _ui->teamTable->setItem   ( _ui->teamTable->rowCount()-1,
                                     4,
                                     new QTableWidgetItem(QString::fromStdString(teams[i].getAscent())));
        _ui->teamTable->setItem   ( _ui->teamTable->rowCount()-1,
                                     5,
                                     new QTableWidgetItem(QString::fromStdString(teams[i].getFastest())));
    }
}

