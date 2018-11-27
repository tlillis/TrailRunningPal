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

void AddAthlete::on_addButton_clicked()
{
    QString name_s = ui->athlete_name->text();

    std::string username = "paul";

    if(name_s != "")
    {
        if(_updater != NULL)
        {
            _updater->write(username,"coach.txt",name_s.toStdString() + "\n");
            _updater->notify(username);
        }
    }
}

AddAthlete::~AddAthlete()
{
    delete ui;
}
