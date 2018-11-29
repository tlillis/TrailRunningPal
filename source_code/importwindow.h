#ifndef IMPORTWINDOW_H
#define IMPORTWINDOW_H

#include "fileupdater.h"

#include <iostream>
#include <fstream>

#include <QMessageBox>
#include <QWidget>

namespace Ui {
class ImportWindow;
}

class FileUpdater;

//! Class for handling GUI to add run to athlete list
/*! Class for handling GUI to add run to athlete list
 */
class ImportWindow : public QWidget
{
    Q_OBJECT

public:
    //! Constructor
    /*! Constructor
     */
    explicit ImportWindow(QWidget *parent = 0);

    //! Set observer to use to notify of update
    /*! Set observer to use to notify of update
     * \param updater observer to use to notify of update
     */
    void setObserver(FileUpdater * updater);

    //! Set coach user to add run to
    /*! Set coach user to add run to
     * \param username coach username to add new athlete to
     */
    void setUser(std::string username);

    ~ImportWindow();

private slots:
    void on_pushButton_Import_clicked();

private:
    FileUpdater * _updater = NULL;
    Ui::ImportWindow *_ui; /*!< Contains all GUI window items and functions !*/
    std::string _user; /*!< Coach user to add to !*/
};

#endif // IMPORTWINDOW_H
