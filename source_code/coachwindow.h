#ifndef COACHWINDOW_H
#define COACHWINDOW_H

#include <QWidget>

#include "importwindow.h"
#include "filedatacontainer.h"

namespace Ui {
class CoachWindow;
}

class CoachWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CoachWindow(QWidget *parent = 0);
    void import_athletes(AthletesDataContainer data);
    ~CoachWindow();

private:
    Ui::CoachWindow *ui;
};

#endif // COACHWINDOW_H
