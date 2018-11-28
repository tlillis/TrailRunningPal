#include "addathlete.h"
#include "ui_addathlete.h"

AddAthlete::AddAthlete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddAthlete)
{
    ui->setupUi(this);
}

void AddAthlete::use_observer(FileUpdater *updater)
{
    _updater = updater;
}

void AddAthlete::use_user(std::string username)
{
    _user = username;
}

void AddAthlete::on_addButton_clicked()
{
    QString name_s = ui->athlete_name->text();

    if(name_s != "")
    {
        if(_updater != NULL)
        {
            _updater->write(_user,"coach.txt",name_s.toStdString() + "\n");
            _updater->notify(_user);
        }
    }
}

AddAthlete::~AddAthlete()
{
    delete ui;
}
