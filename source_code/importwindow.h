#ifndef IMPORTWINDOW_H
#define IMPORTWINDOW_H

#include <QWidget>

namespace Ui {
class ImportWindow;
}

class ImportWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ImportWindow(QWidget *parent = 0);
    ~ImportWindow();

private slots:
    void on_pushButton_Import_clicked();

private:
    Ui::ImportWindow *ui;
};

#endif // IMPORTWINDOW_H
