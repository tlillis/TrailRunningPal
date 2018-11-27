#include "addteamathlete.h"
#include "ui_addteamathlete.h"

AddTeamAthlete::AddTeamAthlete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddTeamAthlete)
{
    ui->setupUi(this);
}

void AddTeamAthlete::use_observer(FileUpdater *updater)
{
    _updater = updater;
}

void AddTeamAthlete::on_addButton_clicked()
{
    QString athlete_s = ui->athlete_name->text();
    QString team_s = ui->team_name->text();

    std::string username = "paul";

    if(athlete_s != "" && team_s != "")
    {
        if(_updater != NULL)
        {
            _updater->write(team_s.toStdString(),"team.txt",athlete_s.toStdString() + "\n");
            _updater->notify(username);
        }
    }
}

AddTeamAthlete::~AddTeamAthlete()
{
    delete ui;
}
