#ifndef LOADFILE_H
#define LOADFILE_H

#include "filedatacontainer.h"

#include <fstream>
#include <iostream>
#include <sstream>
#define _GLIBCXX_USE_C99 1
#include <string>

class LoadInterface
{

    public:
        virtual void load(std::string filename,FileDataContainer* data) const = 0;
};

class LoadFile
{
    private:
        LoadInterface * strategy_;

    public:
        explicit LoadFile(LoadInterface *strategy):strategy_(strategy)
        {
        }

        void set_strategy(LoadInterface *strategy)
        {
            strategy_ = strategy;
        }

        void load(std::string filename,FileDataContainer* data) const
        {
            strategy_->load(filename,data);
        }
};

class LoadRuns: public LoadInterface
{
    public:
        void load(std::string filename,FileDataContainer* data) const override
        {
            filename += "_runs.csv";
            std::ifstream infile(filename.c_str());
            std::vector<RunDataContainer> runs;
            std::string line;
            while(std::getline(infile, line))
            {
                std::cout << line << std::endl;
                RunDataContainer run;
                std::istringstream s(line);
                std::string field;

                // NEED TO REFACTOR THIS

                // Date
                getline(s, field,',');
                run.set_date(field);

                // Time
                getline(s, field,',');
                run.set_time(field);

                // Miles
                getline(s, field,',');
                run.set_miles(field);

                // Elevation Gain
                getline(s, field,',');
                run.set_egain(field);

                // Max Heart Rate
                getline(s, field,',');
                run.set_mhr(field);

                // Average Heart Rate
                getline(s, field,',');
                run.set_ahr(field);

                // Calories
                getline(s, field,',');
                run.set_cals(field);

                // Fastest Mile Time
                getline(s, field,',');
                run.set_fastest(field);

                // Tag
                getline(s, field,',');
                run.set_tag(field);

                // Put in vector
                runs.push_back(run);
            }
            std::cout << "Import size: " << runs.size() << std::endl;
            ((RunsDataContainer*)data)->set_runs(runs);
        }
};

class LoadCredentials: public LoadInterface
{
    public:
        void load(std::string filename,FileDataContainer* data) const override
        {
            filename += "_creds";
            std::ifstream infile(filename.c_str());
            std::string password;
            infile >> password;
            ((CredentialsDataContainer*)data)->set_password(password);
        }
};

class LoadAthlete: public LoadInterface
{
    public:
        void load(std::string filename,FileDataContainer* data) const override
        {
            filename += "_stats.txt";
            std::ifstream infile(filename.c_str());
            std::string line;
            while(std::getline(infile, line))
            {
                std::cout << line << std::endl;
                std::istringstream s(line);
                std::string field;

                getline(s, field,',');
                ((AthleteDataContainer*)data)->set_name(field);

                getline(s, field,',');
                ((AthleteDataContainer*)data)->set_miles(field);

                getline(s, field,',');
                ((AthleteDataContainer*)data)->set_ytd_miles(field);

                getline(s, field,',');
                ((AthleteDataContainer*)data)->set_last_miles(field);

                getline(s, field,',');
                ((AthleteDataContainer*)data)->set_pace(field);

                getline(s, field,',');
                ((AthleteDataContainer*)data)->set_ytd_pace(field);

                getline(s, field,',');
                ((AthleteDataContainer*)data)->set_ascent(field);

                getline(s, field,',');
                ((AthleteDataContainer*)data)->set_ytd_ascent(field);

                getline(s, field,',');
                ((AthleteDataContainer*)data)->set_mile1(field);

                getline(s, field,',');
                ((AthleteDataContainer*)data)->set_mile2(field);

                getline(s, field,',');
                ((AthleteDataContainer*)data)->set_k5(field);

                getline(s, field,',');
                ((AthleteDataContainer*)data)->set_k10(field);

                getline(s, field,',');
                ((AthleteDataContainer*)data)->set_half_mar(field);

                getline(s, field,',');
                ((AthleteDataContainer*)data)->set_mar(field);

                getline(s, field,',');
                ((AthleteDataContainer*)data)->set_mile50(field);
            }
        }
};

class LoadCoach: public LoadInterface
{
    public:
        void load(std::string filename,FileDataContainer* data) const override
        {
            filename += "_coach.txt";
            std::ifstream infile(filename.c_str());
            std::string line;
            std::vector <AthleteDataContainer> athletes;
            LoadAthlete load_athlete;
            while(std::getline(infile, line))
            {
                std::cout << line << std::endl;
                AthleteDataContainer athlete;
                LoadFile file_loader(&load_athlete);
                file_loader.load(line,&athlete);
                athletes.push_back(athlete);
            }
            ((AthletesDataContainer*)data)->set_athletes(athletes);
        }
};

class LoadTeam: public LoadInterface
{
    public:
        void load(std::string filename,FileDataContainer* data) const override
        {
            std::cout << "Loading team " << filename << std::endl;
            std::string name = filename;
            filename += "_team.txt";
            std::ifstream infile(filename.c_str());
            std::string line;
            std::vector <AthleteDataContainer> athletes;
            LoadAthlete load_athlete;
            while(std::getline(infile, line))
            {
                std::cout << line << std::endl;
                AthleteDataContainer athlete;
                LoadFile file_loader(&load_athlete);
                file_loader.load(line,&athlete);
                athletes.push_back(athlete);
            }

            int size = athletes.size();
            int miles = 0;
            int pace = 0;
            int ascent = 0;
            int fastest_pace = 0;
            std::string fastest;

            std::string::size_type sz;

            for(unsigned int i = 0; i < athletes.size(); i++)
            {
                miles += std::stoi(athletes[i].get_miles(),&sz);
                pace += std::stoi(athletes[i].get_pace(),&sz);
                ascent += std::stoi(athletes[i].get_ascent(),&sz);
                if(std::stoi(athletes[i].get_pace(),&sz) > fastest_pace)
                {
                    fastest_pace = std::stoi(athletes[i].get_pace(),&sz);
                    fastest = athletes[i].get_name();
                }
            }

            pace = pace / size;

            ((TeamDataContainer*)data)->set_name(name);
            ((TeamDataContainer*)data)->set_athletes(std::to_string(size));
            ((TeamDataContainer*)data)->set_miles(std::to_string(miles));
            ((TeamDataContainer*)data)->set_pace(std::to_string(pace));
            ((TeamDataContainer*)data)->set_ascent(std::to_string(ascent));
            ((TeamDataContainer*)data)->set_fastest(fastest);
        }
};

class LoadTeams: public LoadInterface
{
    public:
        void load(std::string filename,FileDataContainer* data) const override
        {
            std::cout << "Loading teams for " << filename << std::endl;
            filename += "_teams.txt";
            std::ifstream infile(filename.c_str());
            std::string line;
            std::vector <TeamDataContainer> teams;
            LoadTeam load_team;
            while(std::getline(infile, line))
            {
                std::cout << line << std::endl;
                TeamDataContainer team;
                LoadFile file_loader(&load_team);
                file_loader.load(line,&team);
                teams.push_back(team);
            }
            ((TeamsDataContainer*)data)->set_teams(teams);
        }
};
/**
class LoadRuns: public LoadInterface
{
public:
    LoadRuns() {}
    void load(std::string filename,FileDataContainer* data) const override;
};

class LoadCredentials: public LoadInterface
{
public:
    LoadCredentials() {}
    void load(std::string filename,FileDataContainer* data) const override;
};

class LoadAthlete: public LoadInterface
{
public:
    LoadAthlete() {}
    void load(std::string filename,FileDataContainer* data) const override;
};

class LoadCoach: public LoadInterface
{
public:
    LoadCoach() {}
    void load(std::string filename,FileDataContainer* data) const override;
};

class LoadTeam: public LoadInterface
{
public:
    LoadTeam() {}
    void load(std::string filename,FileDataContainer* data) const override;
};

class LoadTeams: public LoadInterface
{
public:
    LoadTeams() {}
    void load(std::string filename,FileDataContainer* data) const override;
};
**/
#endif // LOADFILE_H
