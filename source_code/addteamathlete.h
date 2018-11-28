#ifndef ADDTEAMATHLETE_H
#define ADDTEAMATHLETE_H

#include <QWidget>
#include "fileupdater.h"

namespace Ui {
class AddTeamAthlete;
}

class FileUpdater;

class AddTeamAthlete : public QWidget
{
    Q_OBJECT

public:
    explicit AddTeamAthlete(QWidget *parent = 0);
    void use_user(std::string username);
    void use_observer(FileUpdater * updater);
    ~AddTeamAthlete();

private slots:
    void on_addButton_clicked();

private:
    Ui::AddTeamAthlete *ui;
    FileUpdater * _updater = NULL;
    std::string _user;
};

#endif // ADDTEAMATHLETE_H
