#include "fileupdater.h"


// Subject
FileUpdater::FileUpdater()
{

}

int FileUpdater::clear(std::string filename)
{
    std::cout << filename << std::endl;
    return 0;
}


int FileUpdater::write(std::string username, std::string fileType , std::string content)
{
    std::string oldData;
    std::string line;
    std::string filename = username + "_" + fileType;
    std::ifstream infile(filename.c_str());
    if (infile.is_open())
    {
        while (getline (infile,line))
        {
          oldData += line + "\n";
        }
        infile.close();
    }

    content += oldData;

    std::ofstream outfile(filename.c_str());
    if (outfile.is_open())
    {
        outfile << content;
        outfile.close();
    }
    std::cout << "Wrote new data" << std::endl;
    return 0;
}

int FileUpdater::notify(std::string username)
{
    std::cout << _obs.size() << std::endl;
    for(unsigned int i = 0; i < _obs.size(); i++)
    {
        std::cout << "notifying obs " << i << std::endl;
        _obs[i]->update(username);
    }
    return 0;
}

int FileUpdater::attach(Observer *obs)
{
    std::cout << "attaching obs" << std::endl;
    _obs.push_back(obs);
    return 0;
}


void AthleteObserver::update(std::string username) {
    LoadAthlete loadAthlete;
    LoadRuns loadRuns;

    AthleteDataContainer athleteData;
    LoadFile file_loader(&loadAthlete);
    file_loader.load(username,&athleteData);
    _window->importAthlete(athleteData);

    RunsDataContainer runData;
    file_loader.set_strategy(&loadRuns);
    file_loader.load(username,&runData);
    _window->importRuns(runData);
}

void AthleteObserver::setWindow(AthlWindow * window) {
    _window = window;
}

void CoachObserver::update(std::string username)
{
    LoadCoach loadCoach;
    LoadTeams loadTeam;

    AthletesDataContainer athletes;
    LoadFile file_loader(&loadCoach);
    file_loader.load(username,&athletes);
    _window->importAthletes(athletes);

    TeamsDataContainer teams;
    file_loader.set_strategy(&loadTeam);
    file_loader.load(username,&teams);
    _window->importTeams(teams);
}

void CoachObserver::setWindow(CoachWindow * window) {
    _window = window;
}
