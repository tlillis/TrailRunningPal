#ifndef ATHLWINDOW_H
#define ATHLWINDOW_H

#include "filedatacontainer.h"
#include "fileupdater.h"
#include "importwindow.h"

#include <QWidget>
#include <QMessageBox>


namespace Ui {
class AthlWindow;
}

class FileUpdater;

class AthlWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AthlWindow(QWidget *parent = 0);
    void import_runs(RunsDataContainer data);
    void import_athlete(AthleteDataContainer data);
    void use_user(std::string username);
    ~AthlWindow();

private slots:
    void on_pushButton_Import_clicked();

private:
    Ui::AthlWindow *ui;
    std::string _user;
};

#endif // ATHLWINDOW_H
