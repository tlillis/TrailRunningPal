#ifndef ADDTEAMATHLETE_H
#define ADDTEAMATHLETE_H

#include "fileupdater.h"

#include <QWidget>

namespace Ui {
class AddTeamAthlete;
}

class FileUpdater;

//! Class for handling GUI to add athlete to teams list
/*! Class for handling GUI to add athlete to teams list
 */
class AddTeamAthlete : public QWidget
{
    Q_OBJECT

public:
    //! Constructor
    /*! Constructor
     */
    explicit AddTeamAthlete(QWidget *parent = 0);

    //! Set coach user to add athlete to team
    /*! Set coach user to add athlete to team
     * \param username coach username to add new athlete to
     */
    void setUser(std::string username);

    //! Set observer to use to notify of update
    /*! Set observer to use to notify of update
     * \param updater observer to use to notify of update
     */
    void setObserver(FileUpdater * updater);

    //! Destructor
    /*! Destructor
     */
    ~AddTeamAthlete();

private slots:
    void on_addButton_clicked();

private:
    Ui::AddTeamAthlete *_ui; /*!< Contains all GUI window items and functions !*/
    FileUpdater *_updater = NULL; /*!< Observer to use !*/
    std::string _user; /*!< Coach user to add to !*/
};

#endif // ADDTEAMATHLETE_H
