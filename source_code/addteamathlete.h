#ifndef ADDTEAMATHLETE_H
#define ADDTEAMATHLETE_H

#include "fileupdater.h"

#include <QWidget>

namespace Ui {
class AddTeamAthlete;
}

class FileUpdater;

class AddTeamAthlete : public QWidget
{
    Q_OBJECT

public:
    explicit AddTeamAthlete(QWidget *parent = 0);
    void setUser(std::string username);
    void setObserver(FileUpdater * updater);
    ~AddTeamAthlete();

private slots:
    void on_addButton_clicked();

private:
    Ui::AddTeamAthlete *_ui;
    FileUpdater * _updater = NULL;
    std::string _user;
};

#endif // ADDTEAMATHLETE_H
