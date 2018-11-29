#ifndef FILEUPDATER_H
#define FILEUPDATER_H

#include "athlwindow.h"
#include "coachwindow.h"
#include "loadfile.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

//! Interface for implementing observers
/*! Interface for implementing observers
 */
class Observer
{
public:
    //! Action that takes place when notified
    /*! Action that takes place when notified
     * \param username user that owns window
     */
    virtual void update(std::string username) = 0;
};

class AthlWindow;
class CoachWindow;

//! Class that updates files and notifies observers when files change
/*! Class that updates files and notifies observers when files change
 */
class FileUpdater
{
private:
    std::vector <class Observer *> _obs;
public:
    //! Clear given file
    /*! Clear contents of given file
     * \param filename to clear
     */
    int clear(std::string filename);

    //! Prepend data to storage file
    /*! Prepend data to storage file
     * \param filename filename to write to
     * \param fileType type of file to write to
     * \param content to append
     */
    int write(std::string filename, std::__cxx11::string fileType, std::string content);

    //! Notify obervers that file has changed
    /*! Notify obervers that file has changed
     * \param username username of owner of file that has changed
     */
    int notify(std::__cxx11::string username);

    //! Attach observer to be notified
    /*! Attach observer to be notified
     * \param obs observer to be attached and notified when notify is called
     */
    int attach(Observer *obs);

    //! Constructor
    /*! Constructor
     */
    FileUpdater();
};

//! Class that updates athlete interface when file has been updated
/*! Class that updates athlete interface when file has been updated
 */
class AthleteObserver: public Observer {
private:
    AthlWindow * _window = NULL;
public:
    //! Set window observer will update
    /*! Set window observer will update
     * \param window window observer will update
     */
    void setWindow(AthlWindow * window);

    //! Updates window interface when notified
    /*! Updates widnow interface when notified
     * \param username user that owns window
     */
    void update(std::string username);
};

//! Class that updates coach interface when file has been updated
/*! Class that updates coach interface when file has been updated
 */
class CoachObserver: public Observer {
private:
    CoachWindow * _window = NULL;
public:
    //! Set window observer will update
    /*! Set window observer will update
     * \param window window observer will update
     */
    void setWindow(CoachWindow * window);

    //! Updates window interface when notified
    /*! Updates widnow interface when notified
     * \param username user that owns window
     */
    void update(std::string username);
};

#endif // FILEUPDATER_H
