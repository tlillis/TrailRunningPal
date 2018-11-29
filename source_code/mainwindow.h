#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "athlwindow.h"
#include "coachwindow.h"
#include "ui_mainwindow.h"
#include "login.h"

#include <iostream>

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

//! Class for maintaining main window GUI
/*! Class for maintaining main window GUI
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //! Constructor
    /*! Constructor
     */
    explicit MainWindow(QWidget *parent = 0);

    //! Destructor
    /*! Desstructor
     */
    ~MainWindow();

private slots:
    /*! Function that is called when login button clicked on login screen !*/
    void on_pushButton_Login_clicked();

    /*! Function that is called when athlete radio button clicked on login screen !*/
    void on_radioButton_athelete_clicked();

    /*! Function that is called when coach radio button clicked on login screen !*/
    void on_radioButton_coach_clicked();

private:
    QString _loginType;  /*!< Handles the login type depending on which radio button clicked !*/
    Ui::MainWindow *_ui; /*!< Contains all GUI window items and functions !*/
};

#endif // MAINWINDOW_H
