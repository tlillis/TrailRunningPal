#ifndef IMPORTWINDOW_H
#define IMPORTWINDOW_H

#include "fileupdater.h"

#include <iostream>
#include <fstream>

#include <QMessageBox>
#include <QWidget>

namespace Ui {
class ImportWindow;
}

class FileUpdater;

class ImportWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ImportWindow(QWidget *parent = 0);
    void setObserver(FileUpdater * updater);
    void setUser(std::string username);
    void updateStats(AthleteDataContainer *data);

    ~ImportWindow();

private slots:
    void on_pushButton_Import_clicked();

private:
    FileUpdater * _updater = NULL;
    Ui::ImportWindow *_ui;
    std::string _user;
};

#endif // IMPORTWINDOW_H
