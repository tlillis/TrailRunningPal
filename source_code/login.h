#ifndef LOGIN_H
#define LOGIN_H

#include "athlwindow.h"
#include "coachwindow.h"
#include "loadfile.h"
#include "filedatacontainer.h"

class Login
{
public:
    Login();
    int login(std::string username, std::string password);
protected:
    virtual int checkCredentials(std::string username, std::string password) = 0;
    virtual void startWindow() = 0;
    virtual void loadData(std::string username) = 0;
};


class AthleteLogin : public Login
{
public:
    AthleteLogin();
    int checkCredentials(std::string username, std::string password);
    void startWindow();
    void loadData(std::string username);
private:
    AthlWindow *athelete_window;
};

class CoachLogin : public Login
{
public:
    CoachLogin();
    int checkCredentials(std::string username, std::string password);
    void startWindow();
    void loadData(std::string username);
private:
    CoachWindow *coach_window;
};


#endif // LOGIN_H
