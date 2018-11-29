#ifndef ATHLWINDOW_H
#define ATHLWINDOW_H

#include "filedatacontainer.h"
#include "fileupdater.h"
#include "importwindow.h"

#include <QWidget>
#include <QMessageBox>


namespace Ui {
class AthlWindow;
}

class FileUpdater;

//! Class for maintaining athlete GUI
/*! Class for maintaining athlete GUI
 */
class AthlWindow : public QWidget
{
    Q_OBJECT

public:
    //! Constructor
    /*! Constructor
     */
    explicit AthlWindow(QWidget *parent = 0);

    //! Adds runs data to GUI
    /*! Adds runs data to GUI
     * \param data runs data to be added to GUI
     */
    void importRuns(RunsDataContainer data);

    //! Adds athlete data to GUI
    /*! Adds athlete data to GUI
     * \param data athlete data to be added to GUI
     */
    void importAthlete(AthleteDataContainer data);

    //! Sets the user of the GUI and updates GUI with that name
    /*! Sets the user of the GUI and updates GUI with that name
     * \param username username of owner of GUI
     */
    void setUser(std::string username);

    //! Destructor
    /*! Destructor
     */
    ~AthlWindow();

private slots:
    void on_pushButton_Import_clicked();

private:
    Ui::AthlWindow *_ui; /*!< Contains all GUI window items and functions !*/
    std::string _user;
};

#endif // ATHLWINDOW_H
