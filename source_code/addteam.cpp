#include "addteam.h"
#include "ui_addteam.h"

AddTeam::AddTeam(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::AddTeam)
{
    _ui->setupUi(this);
}

void AddTeam::useObserver(FileUpdater *updater)
{
    _updater = updater;
}

void AddTeam::useUser(std::string username)
{
    _user = username;
}


void AddTeam::on_addButton_clicked()
{
    QString nameS = _ui->team_name->text();

    if(nameS != "")
    {
        if(_updater != NULL)
        {
            _updater->write(_user,"teams.txt",nameS.toStdString() + "\n");
            _updater->notify(_user);
        }
    }
}

AddTeam::~AddTeam()
{
    delete _ui;
}
