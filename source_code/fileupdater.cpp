#include "fileupdater.h"
#include "loadfile.h"

#include <fstream>
#include <iostream>
#include <sstream>

// Subject
FileUpdater::FileUpdater()
{

}

int FileUpdater::clear(std::string filename)
{
    std::cout << filename << std::endl;
    return 0;
}


int FileUpdater::write(std::string username, std::string file_type ,std::string content)
{
    std::string old_data;
    std::string line;
    std::string filename = username + "_" + file_type;
    std::ifstream infile(filename.c_str());
    if (infile.is_open())
    {
        while (getline (infile,line))
        {
          old_data += line + "\n";
        }
        infile.close();
    }

    content += old_data;

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
    LoadAthlete load_athlete;
    LoadRuns load_runs;

    AthleteDataContainer data_a;
    LoadFile file_loader(&load_athlete);
    file_loader.load(username,&data_a);
    _window->import_athlete(data_a);

    RunsDataContainer data_r;
    file_loader.set_strategy(&load_runs);
    file_loader.load(username,&data_r);
    _window->import_runs(data_r);
}

void AthleteObserver::use_window(AthlWindow * window) {
    _window = window;
}

void CoachObserver::update(std::string username)
{
    LoadCoach load_coach;
    LoadTeams load_team;

    AthletesDataContainer athletes;
    LoadFile file_loader(&load_coach);
    file_loader.load(username,&athletes);
    _window->import_athletes(athletes);

    TeamsDataContainer teams;
    file_loader.set_strategy(&load_team);
    file_loader.load(username,&teams);
    _window->import_teams(teams);
}

void CoachObserver::use_window(CoachWindow * window) {
    _window = window;
}
