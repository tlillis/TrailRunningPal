#ifndef ADDTEAM_H
#define ADDTEAM_H

#include "fileupdater.h"

#include <QWidget>

namespace Ui {
class AddTeam;
}

class FileUpdater;

class AddTeam : public QWidget
{
    Q_OBJECT

public:
    explicit AddTeam(QWidget *parent = 0);
    void useUser(std::string username);
    void useObserver(FileUpdater * updater);
    ~AddTeam();

private slots:
    void on_addButton_clicked();

private:
    Ui::AddTeam *_ui;
    FileUpdater * _updater = NULL;
    std::string _user;
};

#endif // ADDTEAM_H
