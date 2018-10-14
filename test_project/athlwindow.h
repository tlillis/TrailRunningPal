#ifndef ATHLWINDOW_H
#define ATHLWINDOW_H

#include <QWidget>

namespace Ui {
class AthlWindow;
}

class AthlWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AthlWindow(QWidget *parent = 0);
    ~AthlWindow();

private:
    Ui::AthlWindow *ui;
};

#endif // ATHLWINDOW_H
