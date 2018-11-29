#ifndef ADDTEAM_H
#define ADDTEAM_H

#include "fileupdater.h"

#include <QWidget>

namespace Ui {
class AddTeam;
}

class FileUpdater;

//! Class for handling GUI to add team to coaches list
/*! Class for handling GUI to add team to coaches list
 */
class AddTeam : public QWidget
{
    Q_OBJECT

public:
    //! Constructor
    /*! Constructor
     */
    explicit AddTeam(QWidget *parent = 0);

    //! Set coach user to add team to
    /*! Set coach user to add team to
     * \param username coach username to add new team to
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
    ~AddTeam();

private slots:
    void on_addButton_clicked();

private:
    Ui::AddTeam *_ui; /*!< Contains all GUI window items and functions !*/
    FileUpdater *_updater = NULL; /*!< Observer to use !*/
    std::string _user; /*!< Coach user to add to !*/
};

#endif // ADDTEAM_H
