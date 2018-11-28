#ifndef IMPORTWINDOW_H
#define IMPORTWINDOW_H

#include <QMessageBox>
#include <QWidget>

#include <iostream>
#include <fstream>

#include "fileupdater.h"

namespace Ui {
class ImportWindow;
}

class FileUpdater;

class ImportWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ImportWindow(QWidget *parent = 0);
    void use_observer(FileUpdater * updater);
    void use_user(std::string username);
    void update_stats(AthleteDataContainer *data);

    ~ImportWindow();

private slots:
    void on_pushButton_Import_clicked();

private:
    FileUpdater * _updater = NULL;
    Ui::ImportWindow *ui;
    std::string _user;
};

#endif // IMPORTWINDOW_H
