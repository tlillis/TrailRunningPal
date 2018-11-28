#ifndef ADDATHLETE_H
#define ADDATHLETE_H

#include "fileupdater.h"

#include <QWidget>

namespace Ui {
class AddAthlete;
}

class FileUpdater;

class AddAthlete : public QWidget
{
    Q_OBJECT

public:
    explicit AddAthlete(QWidget *parent = 0);
    void setUser(std::string username);
    void useObserver(FileUpdater * updater);
    ~AddAthlete();

private slots:
    void on_addButton_clicked();

private:
    Ui::AddAthlete *_ui;
    FileUpdater * _updater = NULL;
    std::string _user;
};

#endif // ADDATHLETE_H
