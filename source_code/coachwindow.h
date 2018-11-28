#ifndef COACHWINDOW_H
#define COACHWINDOW_H

#include <QWidget>

#include "filedatacontainer.h"
#include "fileupdater.h"
#include "addathlete.h"
#include "addteam.h"
#include "addteamathlete.h"

namespace Ui {
class CoachWindow;
}

class FileUpdater;

class CoachWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CoachWindow(QWidget *parent = 0);
    void import_athletes(AthletesDataContainer data);
    void import_teams(TeamsDataContainer data);
    void use_user(std::string username);
    ~CoachWindow();
private slots:
    void on_athleteButton_clicked();
    void on_teamButton_clicked();
    void on_ateamButton_clicked();

private:
    Ui::CoachWindow *ui;
    std::string _user;
};

#endif // COACHWINDOW_H
