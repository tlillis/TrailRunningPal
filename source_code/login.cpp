#include "login.h"


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
    LoadCredentials loadCredentials;
    LoadFile fileLoader(&loadCredentials);
    fileLoader.load(username,&data);

    std::cout << password << std::endl;
    if(data.getPassword()==password) {
        return 1;
    }
    return -1;
}

void AthleteLogin::loadData(std::string username)
{
    _atheleteWindow->setUser(username);

    LoadAthlete loadAthlete;
    LoadRuns loadRuns;

    AthleteDataContainer athleteData;
    LoadFile file_loader(&loadAthlete);
    file_loader.load(username,&athleteData);
    _atheleteWindow->importAthlete(athleteData);

    RunsDataContainer runData;
    file_loader.set_strategy(&loadRuns);
    file_loader.load(username,&runData);
    _atheleteWindow->importRuns(runData);
}

void AthleteLogin::startWindow()
{
    _atheleteWindow = new AthlWindow();
    _atheleteWindow->show();
}

CoachLogin::CoachLogin()
{

}

void CoachLogin::startWindow()
{
    _coachWindow = new CoachWindow();
    _coachWindow->show();
}

void CoachLogin::loadData(std::__cxx11::string username)
{
    _coachWindow->setUser(username);

    LoadCoach loadCoach;
    LoadTeams loadTeam;

    AthletesDataContainer athletes;
    LoadFile file_loader(&loadCoach);
    file_loader.load(username,&athletes);
    _coachWindow->importAthletes(athletes);

    TeamsDataContainer teams;
    file_loader.set_strategy(&loadTeam);
    file_loader.load(username,&teams);
    _coachWindow->importTeams(teams);
}

int CoachLogin::checkCredentials(std::string username,std::string password)
{
    CredentialsDataContainer data;
    std::cout << "check creds" << std::endl;
    LoadCredentials loadCredentials;
    LoadFile fileLoader(&loadCredentials);
    fileLoader.load(username,&data);

    if(data.getPassword()==password) {
        return 1;
    }
    return -1;
}
