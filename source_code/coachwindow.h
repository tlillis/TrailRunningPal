#ifndef COACHWINDOW_H
#define COACHWINDOW_H

#include <QWidget>

namespace Ui {
class CoachWindow;
}

class CoachWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CoachWindow(QWidget *parent = 0);
    ~CoachWindow();

private:
    Ui::CoachWindow *ui;
};

#endif // COACHWINDOW_H
