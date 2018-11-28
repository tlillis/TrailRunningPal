#ifndef ADDTEAM_H
#define ADDTEAM_H

#include <QWidget>
#include "fileupdater.h"

namespace Ui {
class AddTeam;
}

class FileUpdater;

class AddTeam : public QWidget
{
    Q_OBJECT

public:
    explicit AddTeam(QWidget *parent = 0);
    void use_user(std::string username);
    void use_observer(FileUpdater * updater);
    ~AddTeam();

private slots:
    void on_addButton_clicked();

private:
    Ui::AddTeam *ui;
    FileUpdater * _updater = NULL;
    std::string _user;
};

#endif // ADDTEAM_H
