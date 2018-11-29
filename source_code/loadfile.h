#ifndef LOADFILE_H
#define LOADFILE_H

#include "filedatacontainer.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#define _GLIBCXX_USE_C99 1

//! Interface for defining strategy for loading files
/*! Interface for defining strategy for loading files
 *  Use of strategy design pattern
 */
class LoadInterface
{
    public:
        //! Load data from file
        /*! Load data from file
        * \param filename filename to load from
        * \param data data container to load the data into
        */
        virtual void load(std::string filename,FileDataContainer* data) const = 0;
};

//! Class for handling different file load strategies
/*! Class for handling different file load strategies
 *  Use of strategy design pattern. Loads files in different ways given different strategies
 */
class LoadFile
{
    private:
        LoadInterface * strategy_;

    public:
        //! Constructor for loading file
        /*! Constructor for loading file
         * \param strategy strategy for loading file
         */
        explicit LoadFile(LoadInterface *strategy):strategy_(strategy)
        {
        }

        //! Set strategy for loading file
        /*! Set strategy for loading file
         * \param strategy strategy for loading file
         */
        void set_strategy(LoadInterface *strategy)
        {
            strategy_ = strategy;
        }

        //! Load data from file
        /*! Load data from file
         * \param filename filename to load from
         * \param data data container to load the data into
         */
        void load(std::string filename,FileDataContainer* data) const
        {
            strategy_->load(filename,data);
        }
};

//! Class defining load strategy of files containing runs
/*! Class defining load strategy of files containing runs
 *  Implements load for files that contain run data for an athlete.
 */
class LoadRuns: public LoadInterface
{
    public:
        //! Load data from file containing runs
        /*! Load data from file containing runs
        * \param filename filename to load from
        * \param data data container to load the data into
        */
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

                // Date
                getline(s, field,',');
                run.setDate(field);

                // Time
                getline(s, field,',');
                run.setTime(field);

                // Miles
                getline(s, field,',');
                run.setMiles(field);

                // Elevation Gain
                getline(s, field,',');
                run.setEgain(field);

                // Max Heart Rate
                getline(s, field,',');
                run.setMhr(field);

                // Average Heart Rate
                getline(s, field,',');
                run.setAhr(field);

                // Calories
                getline(s, field,',');
                run.setCals(field);

                // Fastest Mile Time
                getline(s, field,',');
                run.setFastest(field);

                // Tag
                getline(s, field,',');
                run.setTag(field);

                // Put in vector
                runs.push_back(run);
            }
            std::cout << "Import size: " << runs.size() << std::endl;
            ((RunsDataContainer*)data)->setRuns(runs);
        }
};

//! Class defining load strategy of files containing credentials
/*! Class defining load strategy of files containing credentials
 *  Implements load for files that contain credentials for a user.
 */
class LoadCredentials: public LoadInterface
{
    public:
        //! Load data from file containing credentials
        /*! Load data from file containing credentials
        * \param filename filename to load from
        * \param data data container to load the data into
        */
        void load(std::string filename,FileDataContainer* data) const override
        {
            filename += "_creds";
            std::ifstream infile(filename.c_str());
            std::string password;
            infile >> password;
            ((CredentialsDataContainer*)data)->setPassword(password);
        }
};

//! Class defining load strategy of files containing athlete data
/*! Class defining load strategy of files containing athlete data
 *  Implements load for files that contain athlete data for an athlete.
 */
class LoadAthlete: public LoadInterface
{
    public:
        //! Load data from file containing athlete data
        /*! Load data from file containing athlete data
        * \param filename filename to load from
        * \param data data container to load the data into
        */
        void load(std::string filename,FileDataContainer* data) const override
        {
            filename += "_stats.txt";
            std::ifstream infile(filename.c_str());
            std::string line;
            if(std::getline(infile, line))
            {
                std::cout << line << std::endl;
                std::istringstream s(line);
                std::string field;

                getline(s, field,',');
                ((AthleteDataContainer*)data)->setName(field);

                getline(s, field,',');
                ((AthleteDataContainer*)data)->setMiles(field);

                getline(s, field,',');
                ((AthleteDataContainer*)data)->setYtdMiles(field);

                getline(s, field,',');
                ((AthleteDataContainer*)data)->setLastMiles(field);

                getline(s, field,',');
                ((AthleteDataContainer*)data)->setPace(field);

                getline(s, field,',');
                ((AthleteDataContainer*)data)->setYtdPace(field);

                getline(s, field,',');
                ((AthleteDataContainer*)data)->setAscent(field);

                getline(s, field,',');
                ((AthleteDataContainer*)data)->setYtdAscent(field);

                getline(s, field,',');
                ((AthleteDataContainer*)data)->setMile1(field);

                getline(s, field,',');
                ((AthleteDataContainer*)data)->setMile2(field);

                getline(s, field,',');
                ((AthleteDataContainer*)data)->setK5(field);

                getline(s, field,',');
                ((AthleteDataContainer*)data)->setK10(field);

                getline(s, field,',');
                ((AthleteDataContainer*)data)->setHalfMar(field);

                getline(s, field,',');
                ((AthleteDataContainer*)data)->setMar(field);

                getline(s, field,',');
                ((AthleteDataContainer*)data)->setMile50(field);
            }
        }
};

//! Class defining load strategy of files containing coach data
/*! Class defining load strategy of files containing coach data
 *  Implements load for files that contain coach data for a coach.
 */
class LoadCoach: public LoadInterface
{
    public:
        //! Load data from file containing coach data
        /*! Load data from file containing coach data
        * \param filename filename to load from
        * \param data data container to load the data into
        */
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
            ((AthletesDataContainer*)data)->setAthletes(athletes);
        }
};

//! Class defining load strategy of files containing team data
/*! Class defining load strategy of files containing team data
 *  Implements load for files that contain team data for a team.
 */
class LoadTeam: public LoadInterface
{
    public:
        //! Load data from file containing team data
        /*! Load data from file containing team data
        * \param filename filename to load from
        * \param data data container to load the data into
        */
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
            int fastestPace = 0;
            std::string fastest;

            std::string::size_type sz;

            for(unsigned int i = 0; i < athletes.size(); i++)
            {
                miles += std::stoi(athletes[i].getMiles(),&sz);
                pace += std::stoi(athletes[i].getPace(),&sz);
                ascent += std::stoi(athletes[i].getAscent(),&sz);
                if(std::stoi(athletes[i].getPace(),&sz) > fastestPace)
                {
                    fastestPace = std::stoi(athletes[i].getPace(),&sz);
                    fastest = athletes[i].getName();
                }
            }

            pace = pace / size;

            ((TeamDataContainer*)data)->setName(name);
            ((TeamDataContainer*)data)->setAthletes(std::to_string(size));
            ((TeamDataContainer*)data)->setMiles(std::to_string(miles));
            ((TeamDataContainer*)data)->setPace(std::to_string(pace));
            ((TeamDataContainer*)data)->setAscent(std::to_string(ascent));
            ((TeamDataContainer*)data)->setFastest(fastest);
        }
};

//! Class defining load strategy of files containing team lists
/*! Class defining load strategy of files containing team lists
 *  Implements load for files that contain team data for a coach.
 */
class LoadTeams: public LoadInterface
{
    public:
        //! Load data from file containing team lists
        /*! Load data from file containing team lists
        * \param filename filename to load from
        * \param data data container to load the data into
        */
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
            ((TeamsDataContainer*)data)->setTeams(teams);
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
