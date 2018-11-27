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

void AddTeam::on_addButton_clicked()
{
    QString name_s = ui->team_name->text();

    std::string username = "paul";

    if(name_s != "")
    {
        if(_updater != NULL)
        {
            _updater->write(username,"teams.txt",name_s.toStdString() + "\n");
            _updater->notify(username);
        }
    }
}

AddTeam::~AddTeam()
{
    delete ui;
}
