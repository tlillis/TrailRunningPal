#ifndef COACHWINDOW_H
#define COACHWINDOW_H

#include "filedatacontainer.h"
#include "fileupdater.h"
#include "addathlete.h"
#include "addteam.h"
#include "addteamathlete.h"

#include <QWidget>

namespace Ui {
class CoachWindow;
}

class FileUpdater;

class CoachWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CoachWindow(QWidget *parent = 0);
    void importAthletes(AthletesDataContainer data);
    void importTeams(TeamsDataContainer data);
    void setUser(std::string username);
    ~CoachWindow();
private slots:
    void on_athleteButton_clicked();
    void on_teamButton_clicked();
    void on_ateamButton_clicked();

private:
    Ui::CoachWindow *_ui;
    std::string _user;
};

#endif // COACHWINDOW_H
