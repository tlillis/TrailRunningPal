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

//! Class for maintaining coach GUI
/*! Class for maintaining coach GUI
 */
class CoachWindow : public QWidget
{
    Q_OBJECT

public:
    //! Constructor
    /*! Constructor
     */
    explicit CoachWindow(QWidget *parent = 0);

    //! Adds athletes data to GUI
    /*! Adds athletes data to GUI
     * \param data athletes data to be added to GUI
     */
    void importAthletes(AthletesDataContainer data);

    //! Adds teams data to GUI
    /*! Adds teams data to GUI
     * \param data teams data to be added to GUI
     */
    void importTeams(TeamsDataContainer data);

    //! Sets the user of the GUI and updates GUI with that name
    /*! Sets the user of the GUI and updates GUI with that name
     * \param username username of owner of GUI
     */
    void setUser(std::string username);

    //! Destructor
    /*! Destructor
     */
    ~CoachWindow();
private slots:
    void on_athleteButton_clicked();
    void on_teamButton_clicked();
    void on_ateamButton_clicked();

private:
    Ui::CoachWindow *_ui; /*!< Contains all GUI window items and functions !*/
    std::string _user;
};

#endif // COACHWINDOW_H
