#ifndef LOGIN_H
#define LOGIN_H


#include "athlwindow.h"
#include "coachwindow.h"

class Login
{
public:
    Login();
    int login(std::string username, std::string password);
protected:
    virtual void checkCredentials(std::string username, std::string password) = 0;
    virtual void startWindow() = 0;
    virtual void loadData() = 0;
};


class AthleteLogin : public Login
{
public:
    AthleteLogin();
    void checkCredentials(std::string username, std::string password);
    void startWindow();
    void loadData();
private:
    AthlWindow *athelete_window;
};

class CoachLogin : public Login
{
public:
    CoachLogin();
    void startWindow();
private:
    CoachWindow *coach_window;
};


#endif // LOGIN_H
