#include "addathlete.h"
#include "ui_addathlete.h"

AddAthlete::AddAthlete(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::AddAthlete)
{
    _ui->setupUi(this);
}

void AddAthlete::useObserver(FileUpdater *updater)
{
    _updater = updater;
}

void AddAthlete::setUser(std::string username)
{
    _user = username;
}

void AddAthlete::on_addButton_clicked()
{
    QString nameS = _ui->athlete_name->text();

    if(nameS != "")
    {
        if(_updater != NULL)
        {
            _updater->write(_user,"coach.txt",nameS.toStdString() + "\n");
            _updater->notify(_user);
        }
    }
}

AddAthlete::~AddAthlete()
{
    delete _ui;
}
