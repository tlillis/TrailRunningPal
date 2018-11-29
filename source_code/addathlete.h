#ifndef ADDATHLETE_H
#define ADDATHLETE_H

#include "fileupdater.h"

#include <QWidget>

namespace Ui {
class AddAthlete;
}

class FileUpdater;

//! Class for handling GUI to add athlete to coaches list
/*! Class for handling GUI to add athlete to coaches list
 */
class AddAthlete : public QWidget
{
    Q_OBJECT

public:
    //! Constructor
    /*! Constructor
     */
    explicit AddAthlete(QWidget *parent = 0);

    //! Set coach user to add athlete to
    /*! Set coach user to add athlete to
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
    ~AddAthlete();

private slots:
    void on_addButton_clicked();

private:
    Ui::AddAthlete *_ui; /*!< Contains all GUI window items and functions !*/
    FileUpdater *_updater = NULL; /*!< Observer to use !*/
    std::string _user; /*!< Coach user to add to !*/
};

#endif // ADDATHLETE_H
