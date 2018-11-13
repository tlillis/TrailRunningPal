#include "login.h"
#include "loadfile.h"
#include "loadfile.cpp"
#include "filedatacontainer.h"

Login::Login()
{

}

int Login::login(std::string username, std::string password)
{
    std::cout << "login" << std::endl;
    if(checkCredentials(username,password) == 1)
    {
        startWindow();
        loadData(username);
        return 1;
    }
    return -1;
}

AthleteLogin::AthleteLogin()
{

}

int AthleteLogin::checkCredentials(std::string username,std::string password)
{
    CredentialsDataContainer data;
    std::cout << "check creds" << std::endl;
    LoadCredentials load_credentials;
    LoadFile file_loader(&load_credentials);
    file_loader.load(username,&data);

    std::cout << password << std::endl;
    if(data.get_password()==password) {
        return 1;
    }
    return -1;
}

void AthleteLogin::loadData(std::string username)
{
    LoadAthlete load_athlete;
    LoadRuns load_runs;

    LoadFile file_loader(&load_athlete);
    //file_loader.load("test");
    //athelete_window->import_athlete();

    RunsDataContainer data;
    file_loader.set_strategy(&load_runs);
    file_loader.load(username,&data);
    athelete_window->import_runs(data);
}

void AthleteLogin::startWindow()
{
    athelete_window = new AthlWindow();
    athelete_window->show();
}

CoachLogin::CoachLogin()
{

}

void CoachLogin::startWindow()
{
    coach_window = new CoachWindow();
    coach_window->show();
}

void CoachLogin::loadData(std::__cxx11::string username)
{
    LoadAthlete load_athlete;
    LoadRuns load_runs;

    LoadFile file_loader(&load_athlete);
    //file_loader.load("test");
    //athelete_window->import_athlete();

    file_loader.set_strategy(&load_runs);
    //file_loader.load("test");
    //athelete_window->import_runs();
}

int CoachLogin::checkCredentials(std::string username,std::string password)
{
    CredentialsDataContainer data;
    std::cout << "check creds" << std::endl;
    LoadCredentials load_credentials;
    LoadFile file_loader(&load_credentials);
    file_loader.load(username,&data);

    if(data.get_password()==password) {
        return 1;
    }
    return -1;
}