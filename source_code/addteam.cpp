#include "addteam.h"
#include "ui_addteam.h"

AddTeam::AddTeam(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddTeam)
{
    ui->setupUi(this);
}

void AddTeam::use_observer(FileUpdater *updater)
{
    _updater = updater;
}

void AddTeam::use_user(std::string username)
{
    _user = username;
}


void AddTeam::on_addButton_clicked()
{
    QString name_s = ui->team_name->text();

    if(name_s != "")
    {
        if(_updater != NULL)
        {
            _updater->write(_user,"teams.txt",name_s.toStdString() + "\n");
            _updater->notify(_user);
        }
    }
}

AddTeam::~AddTeam()
{
    delete ui;
}
