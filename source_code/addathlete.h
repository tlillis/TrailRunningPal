#ifndef ADDATHLETE_H
#define ADDATHLETE_H

#include <QWidget>
#include "fileupdater.h"

namespace Ui {
class AddAthlete;
}

class FileUpdater;

class AddAthlete : public QWidget
{
    Q_OBJECT

public:
    explicit AddAthlete(QWidget *parent = 0);
    void use_user(std::string username);
    void use_observer(FileUpdater * updater);
    ~AddAthlete();

private slots:
    void on_addButton_clicked();

private:
    Ui::AddAthlete *ui;
    FileUpdater * _updater = NULL;
    std::string _user;
};

#endif // ADDATHLETE_H
