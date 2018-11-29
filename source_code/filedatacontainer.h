#ifndef FILEDATACONTAINER_H
#define FILEDATACONTAINER_H

#include <iostream>
#include <string>
#include <vector>


//! Class for holding and operating on data from files
/*! Class for holding and operating on data from files
 *  Used for polymorphism when loading files
 */
class FileDataContainer
{
public:
    //! Constructor
    /*! Constructor
     */
    FileDataContainer();
private:
    std::string _fileType;
};

//! Class for holding and operating on data from files containing credentials
/*! Class for holding and operating on data from files containing credentials
 */
class CredentialsDataContainer : public FileDataContainer
{
public:
    //! Constructor
    /*! Constructor
     */
    CredentialsDataContainer();

    //! Get username
    /*! Get username
     */
    std::string getUsername();

    //! Set username
    /*! Set username
     */
    void setUsername(std::string username);

    //! Get password
    /*! Get password
     */
    std::string getPassword();

    //! Set password
    /*! Set password
     */
    void setPassword(std::string password);
private:
    std::string _username;
    std::string _password;
};

//! Class for holding and operating on data from files containing run data
/*! Class for holding and operating on data from files containing run data
 */
class RunDataContainer : public FileDataContainer
{
public:
    //! Constructor
    /*! Constructor
     */
    RunDataContainer();

    //! Get date
    /*! Get date
     */
    std::string getDate();

    //! Set date
    /*! Set date
     */
    void setDate(std::string date);

    //! Get time
    /*! Get time
     */
    std::string getTime();

    //! Set time
    /*! Set time
     */
    void setTime(std::string time);

    //! Get miles
    /*! Get miles
     */
    std::string getMiles();

    //! Set miles
    /*! Set miles
     */
    void setMiles(std::string miles);

    //! Get elevation gain
    /*! Get elevation gain
     */
    std::string getEgain();

    //! Set elevation gain
    /*! Set elevation gain
     */
    void setEgain(std::string egain);

    //! Get max heart rate
    /*! Get max heart rate
     */
    std::string getMhr();

    //! Set max heart rate
    /*! Set max heart rate
     */
    void setMhr(std::string mhr);

    //! Get average heart rate
    /*! Get average heart rate
     */
    std::string getAhr();

    //! Set average heart rate
    /*! Set average heart rate
     */
    void setAhr(std::string ahr);

    //! Get calories
    /*! Get calories
     */
    std::string getCals();

    //! Set calories
    /*! Set calories
     */
    void setCals(std::string cals);

    //! Get fastest mile
    /*! Get fastest mile
     */
    std::string getFastest();

    //! Set fastest mile
    /*! Set fastest mile
     */
    void setFastest(std::string fastest);

    //! Get run tag
    /*! Get run tag
     */
    std::string getTag();

    //! Set run tag
    /*! Set run tag
     */
    void setTag(std::string tag);
private:
    std::string _date;
    std::string _time;
    std::string _miles;
    std::string _egain;
    std::string _mhr;
    std::string _ahr;
    std::string _cals;
    std::string _fastest;
    std::string _tag;
};

//! Class for holding and operating on data from files containing athlete data
/*! Class for holding and operating on data from files containing athlete data
 */
class AthleteDataContainer : public FileDataContainer
{
public:
    //! Constructor
    /*! Constructor
     */
    AthleteDataContainer();

    //! Get name
    /*! Get name
     */
    std::string getName();

    //! Set name
    /*! Set name
     */
    void setName(std::string name);

    //! Get miles run
    /*! Get miles run
     */
    std::string getMiles();

    //! Set miles run
    /*! Set miles run
     */
    void setMiles(std::string miles);

    //! Get year to date miles
    /*! Get year to date miles
     */
    std::string getYtdMiles();

    //! Set year to date miles
    /*! Set year to date miles
     */
    void setYtdMiles(std::string ytdMiles);

    //! Get last years miles
    /*! Get last years miles
     */
    std::string getLastMiles();

    //! Set last years miles
    /*! Set last years miles
     */
    void setLastMiles(std::string lastMiles);

    //! Get average pace
    /*! Get average pace
     */
    std::string getPace();

    //! Set average pace
    /*! Set average pace
     */
    void setPace(std::string pace);

    //! Get year to date pace
    /*! Get year to date pace
     */
    std::string getYtdPace();

    //! Set year to date pace
    /*! Set year to date pace
     */
    void setYtdPace(std::string ytdPace);

    //! Get ascent
    /*! Get ascent
     */
    std::string getAscent();

    //! Set ascent
    /*! Set ascent
     */
    void setAscent(std::string ascent);

    //! Get year to date ascent
    /*! Get year to date ascent
     */
    std::string getYtdAscent();

    //! Set year to date ascent
    /*! Set year to date ascent
     */
    void setYtdAscent(std::string ytdAscent);

    //! Get best 1 mile time
    /*! Get best 1 mile time
     */
    std::string getMile1();

    //! Set best 1 mile time
    /*! Set best 1 mile time
     */
    void setMile1(std::string mile1);

    //! Get best 2 mile time
    /*! Get best 2 mile time
     */
    std::string getMile2();

    //! Set best 2 mile time
    /*! Set best 2 mile time
     */
    void setMile2(std::string mile2);

    //! Get best 5K time
    /*! Get best 5K time
     */
    std::string getK5();

    //! Set best 5K time
    /*! Set best 5K time
     */
    void setK5(std::string k5);

    //! Get best 10K time
    /*! Get best 10K time
     */
    std::string getK10();

    //! Set best 10K time
    /*! Set best 10K time
     */
    void setK10(std::string k10);

    //! Get best half marathon time
    /*! Get best half marathon time
     */
    std::string getHalfMar();

    //! Set best half marathon time
    /*! Set best half marathon time
     */
    void setHalfMar(std::string halfMar);

    //! Get best 1 marathon time
    /*! Get best 1 marathon time
     */
    std::string getMar();

    //! Set best 1 marathon time
    /*! Set best 1 marathon time
     */
    void setMar(std::string mar);

    //! Get best 50 mile time
    /*! Get best 50 mile time
     */
    std::string getMile50();

    //! Set best 50 mile time
    /*! Set best 50 mile time
     */
    void setMile50(std::string mile50);
private:
    std::string _name;
    std::string _miles;
    std::string _ytdMiles;
    std::string _lastMiles;
    std::string _pace;
    std::string _ytdPace;
    std::string _ascent;
    std::string _ytdAscent;
    std::string _mile1;
    std::string _mile2;
    std::string _k5;
    std::string _k10;
    std::string _halfMar;
    std::string _mar;
    std::string _mile50;
};

//! Class for holding and operating on data from files containing team data
/*! Class for holding and operating on data from files containing team data
 */
class TeamDataContainer : public FileDataContainer
{
public:
    //! Constructor
    /*! Constructor
     */
    TeamDataContainer();

    //! Get name
    /*! Get name
     */
    std::string getName();

    //! Set name
    /*! Set name
     */
    void setName(std::string name);

    //! Get athletes
    /*! Get athletes
     */
    std::string getAthletes();

    //! Set athletes
    /*! Set athletes
     */
    void setAthletes(std::string athletes);

    //! Get miles
    /*! Get miles
     */
    std::string getMiles();

    //! Set miles
    /*! Set miles
     */
    void setMiles(std::string miles);

    //! Get avg pace
    /*! Get avg pace
     */
    std::string getPace();

    //! Set avg pace
    /*! Set avg pace
     */
    void setPace(std::string pace);

    //! Get ascent
    /*! Get ascent
     */
    std::string getAscent();

    //! Set ascent
    /*! Set ascent
     */
    void setAscent(std::string ascent);

    //! Get fastest athlete
    /*! Get fastest athlete
     */
    std::string getFastest();

    //! Set fastest athlete
    /*! Set fastest athlete
     */
    void setFastest(std::string fastest);
private:
    std::string _name;
    std::string _athletes;
    std::string _miles;
    std::string _pace;
    std::string _ascent;
    std::string _fastest;
};

//! Class for holding and operating on multiple runs data
/*! Class for holding and operating on multiple runs data
 */
class RunsDataContainer : public FileDataContainer
{
public:
    //! Constructor
    /*! Constructor
     */
    RunsDataContainer();

    //! Get run list
    /*! Get run list
     */
    std::vector <RunDataContainer> getRuns();

    //! Set run list
    /*! Set run list
     */
    void setRuns(std::vector<RunDataContainer> runs);
private:
    std::vector<RunDataContainer> _runs;
};

//! Class for holding and operating on multiple athletes data
/*! Class for holding and operating on multiple athletes data
 */
class AthletesDataContainer : public FileDataContainer
{
public:
    //! Constructor
    /*! Constructor
     */
    AthletesDataContainer();

    //! Get athlete list
    /*! Get athlete list
     */
    std::vector <AthleteDataContainer> getAthletes();

    //! Set athlete list
    /*! Set athlete list
     */
    void setAthletes(std::vector<AthleteDataContainer> athletes);
private:
    std::vector<AthleteDataContainer> _athletes;
};

//! Class for holding and operating on multiple teams data
/*! Class for holding and operating on multiple teams data
 */
class TeamsDataContainer : public FileDataContainer
{
public:
    //! Constructor
    /*! Constructor
     */
    TeamsDataContainer();

    //! Get team list
    /*! Get team list
     */
    std::vector <TeamDataContainer> getTeams();

    //! Set team list
    /*! Set team list
     */
    void setTeams(std::vector<TeamDataContainer> teams);
private:
    std::vector<TeamDataContainer> _teams;
};



#endif // FILEDATACONTAINER_H
