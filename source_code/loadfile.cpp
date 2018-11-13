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

class LoadRuns: public LoadInterface
{
    public:
        void load(std::string filename,FileDataContainer* data) const override
        {
            filename += "_runs.csv";
            std::ifstream infile(filename.c_str());
            std::vector<RunData> runs;
            std::string line;
            while(std::getline(infile, line))
            {
                std::cout << line << std::endl;
                RunData run;
                std::istringstream s(line);
                std::string field;

                // NEED TO REFACTOR THIS

                // Date
                getline(s, field,',');
                run.set_date(field);

                getline(s, field,',');
                run.set_time(field);

                getline(s, field,',');
                run.set_miles(field);

                getline(s, field,',');
                run.set_egain(field);

                getline(s, field,',');
                run.set_mhr(field);

                getline(s, field,',');
                run.set_ahr(field);

                getline(s, field,',');
                run.set_cals(field);

                getline(s, field,',');
                run.set_fastest(field);

                /**
                // Time
                getline(s, field,',');
                std::stringstream ss_time(field);
                unsigned int time;
                ss_time >> time;
                run.set_time(time);

                // Miles
                getline(s, field,',');
                std::stringstream ss_miles(field);
                float miles;
                ss_miles >> miles;
                run.set_miles(miles);

                // Elevation Gain
                getline(s, field,',');
                std::stringstream ss_egain(field);
                float egain;
                ss_egain >> egain;
                run.set_egain(egain);

                // Max Heart Rate
                getline(s, field,',');
                std::stringstream ss_mhr(field);
                unsigned int mhr;
                ss_mhr >> mhr;
                run.set_mhr(mhr);

                // Average Heart Rate
                getline(s, field,',');
                std::stringstream ss_ahr(field);
                unsigned int ahr;
                ss_ahr >> ahr;
                run.set_ahr(ahr);

                // Calories
                getline(s, field,',');
                std::stringstream ss_cals(field);
                unsigned int cals;
                ss_cals >> cals;
                run.set_cals(cals);

                // Fastest Mile Time
                getline(s, field,',');
                std::stringstream ss_fastest(field);
                unsigned int fastest;
                ss_fastest >> fastest;
                run.set_fastest(fastest);
                **/
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
            std::ifstream infile(filename.c_str());
            //cout << "Called ConcreteStrategyA execute method" << endl;
        }
};

class LoadCoach: public LoadInterface
{
    public:
        void load(std::string filename,FileDataContainer* data) const override
        {
            std::ifstream infile(filename.c_str());
            //cout << "Called ConcreteStrategyA execute method" << endl;
        }
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
