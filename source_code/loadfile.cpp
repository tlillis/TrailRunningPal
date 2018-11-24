#include "loadfile.h"
#include "filedatacontainer.h"

#include <fstream>
#include <iostream>
#include <sstream>

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
            std::ifstream infile(filename.c_str());
            //cout << "Called ConcreteStrategyA execute method" << endl;
        }
};


