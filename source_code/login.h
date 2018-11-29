#ifndef LOGIN_H
#define LOGIN_H

#include "athlwindow.h"
#include "coachwindow.h"
#include "loadfile.h"
#include "filedatacontainer.h"


//! Class for checking user credentials and pulling user data
/*! Class for handling login of athlete.
 *  Uses template design pattern to do steps needed to login
 *  Implements a function for each of the steps
 *  The steps needed to login are:
 *      1. Check Credentials
 *      2. Load Data for associated user and login type
 *      3. Start window for that user and login type
 */
class Login
{
public:
    Login();
    //! Function that executes login steps
    /*! Function that does all the steps needed for login to account
     * \param username username for login
     * \param password password used for login
     */
    int login(std::string username, std::string password);
protected:
    //! Function that checks credentials. Must be implemented by child
    /*! Function that checks credentials. Must be implemented by child
     * \param username username for login
     * \param password password used for login
     */
    virtual int checkCredentials(std::string username, std::string password) = 0;

    //! Function that starts the GUI. Must be implemented by child
    /*! Function that starts the GUI. Must be implemented by child
     */
    virtual void startWindow() = 0;

    //! Function that loads the users data. Must be implemented by child
    /*! Function that loads the users data. Must be implemented by child
     * \param username username for login
     */
    virtual void loadData(std::string username) = 0;
};


//! Class for checking user credentials and pulling user data for athlete login
/*! Class for handling login of user.
 *  Uses template design pattern to do steps needed to login
 *  The steps needed to login are:
 *      1. Check Credentials
 *      2. Load Data for associated user and login type
 *      3. Start window for that user and login type
 */
class AthleteLogin : public Login
{
public:
    AthleteLogin();

    //! Function that checks credentials for athletes
    /*! Function that checks credentials for athletes
     * \param username username for login
     * \param password password used for login
     */
    int checkCredentials(std::string username, std::string password);

    //! Function that starts the GUI for athletes
    /*! Function that starts the GUI for athletes
     */
    void startWindow();

    //! Function that loads the athletes data
    /*! Function that loads the athletes data
     * \param username username for login
     */
    void loadData(std::string username);
private:
    AthlWindow *_atheleteWindow;
};

//! Class for checking user credentials and pulling user data for coach login
/*! Class for handling login of coach.
 *  Uses template design pattern to do steps needed to login
 *  Implements a function for each of the steps
 *  The steps needed to login are:
 *      1. Check Credentials
 *      2. Load Data for associated user and login type
 *      3. Start window for that user and login type
 */
class CoachLogin : public Login
{
public:
    CoachLogin();

    //! Function that checks credentials for coaches
    /*! Function that checks credentials for coaches
     * \param username username for login
     * \param password password used for login
     */
    int checkCredentials(std::string username, std::string password);

    //! Function that starts the GUI for coaches
    /*! Function that starts the GUI for coaches
     */
    void startWindow();

    //! Function that loads the coaches data
    /*! Function that loads the coaches data
     * \param username username for login
     */
    void loadData(std::string username);
private:
    CoachWindow *_coachWindow;
};


#endif // LOGIN_H
