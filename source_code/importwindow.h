#ifndef IMPORTWINDOW_H
#define IMPORTWINDOW_H

#include <QWidget>

#include "fileupdater.h"

namespace Ui {
class ImportWindow;
}

class ImportWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ImportWindow(QWidget *parent = 0);
    void use_observer(FileUpdater * updater);

    ~ImportWindow();

private slots:
    void on_pushButton_Import_clicked();

private:
    FileUpdater * _updater = NULL;
    Ui::ImportWindow *ui;
};

#endif // IMPORTWINDOW_H
