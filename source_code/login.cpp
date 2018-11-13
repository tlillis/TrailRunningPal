#include "login.h"

Login::Login()
{

}

int Login::login(std::string username, std::string password)
{
    checkCredentials(username,password);
    startWindow();
    loadData();
    return 0;
}

AthleteLogin::AthleteLogin()
{

}

void AthleteLogin::checkCredentials(std::string username,std::string password)
{
}

void AthleteLogin::loadData()
{
}

void AthleteLogin::startWindow()
{
    athelete_window = new AthlWindow();
    athelete_window->show();
}

void CoachLogin::startWindow()
{
    coach_window = new CoachWindow();
    coach_window->show();
}
