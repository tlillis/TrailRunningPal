#ifndef ATHLWINDOW_H
#define ATHLWINDOW_H

#include <QWidget>

#include "importwindow.h"
#include "filedatacontainer.h"

namespace Ui {
class AthlWindow;
}

class AthlWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AthlWindow(QWidget *parent = 0);
    void import_runs(RunsDataContainer data);
    ~AthlWindow();

private slots:
    void on_pushButton_Import_clicked();

private:
    Ui::AthlWindow *ui;
};

#endif // ATHLWINDOW_H
