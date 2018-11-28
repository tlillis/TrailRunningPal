#include "addteamathlete.h"
#include "ui_addteamathlete.h"

AddTeamAthlete::AddTeamAthlete(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::AddTeamAthlete)
{
    _ui->setupUi(this);
}

void AddTeamAthlete::setObserver(FileUpdater *updater)
{
    _updater = updater;
}

void AddTeamAthlete::setUser(std::string username)
{
    _user = username;
}


void AddTeamAthlete::on_addButton_clicked()
{
    QString athleteS = _ui->athlete_name->text();
    QString teamS = _ui->team_name->text();

    if(athleteS != "" && teamS != "")
    {
        if(_updater != NULL)
        {
            _updater->write(teamS.toStdString(),"team.txt",athleteS.toStdString() + "\n");
            _updater->notify(_user);
        }
    }
}

AddTeamAthlete::~AddTeamAthlete()
{
    delete _ui;
}
