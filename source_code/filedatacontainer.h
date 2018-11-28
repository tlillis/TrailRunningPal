#ifndef FILEDATACONTAINER_H
#define FILEDATACONTAINER_H

#include <iostream>
#include <string>
#include <vector>

class FileDataContainer
{
public:
    FileDataContainer();
private:
    std::string _fileType;
};

class CredentialsDataContainer : public FileDataContainer
{
public:
    CredentialsDataContainer();
    std::string getUsername();
    void setUsername(std::string username);
    std::string getPassword();
    void setPassword(std::string password);
private:
    std::string _username;
    std::string _password;
};

class RunDataContainer : public FileDataContainer
{
public:
    RunDataContainer();
    std::string getDate();
    void setDate(std::string date);
    std::string getTime();
    void setTime(std::string time);
    std::string getMiles();
    void setMiles(std::string miles);
    std::string getEgain();
    void setEgain(std::string egain);
    std::string getMhr();
    void setMhr(std::string mhr);
    std::string getAhr();
    void setAhr(std::string ahr);
    std::string getCals();
    void setCals(std::string cals);
    std::string getFastest();
    void setFastest(std::string fastest);
    std::string getTag();
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

class AthleteDataContainer : public FileDataContainer
{
public:
    AthleteDataContainer();
    std::string getName();
    void setName(std::string name);
    std::string getMiles();
    void setMiles(std::string miles);
    std::string getYtdMiles();
    void setYtdMiles(std::string ytdMiles);
    std::string getLastMiles();
    void setLastMiles(std::string lastMiles);
    std::string getPace();
    void setPace(std::string pace);
    std::string getYtdPace();
    void setYtdPace(std::string ytdPace);
    std::string getAscent();
    void setAscent(std::string ascent);
    std::string getYtdAscent();
    void setYtdAscent(std::string ytdAscent);
    std::string getMile1();
    void setMile1(std::string mile1);
    std::string getMile2();
    void setMile2(std::string mile2);
    std::string getK5();
    void setK5(std::string k5);
    std::string getK10();
    void setK10(std::string k10);
    std::string getHalfMar();
    void setHalfMar(std::string halfMar);
    std::string getMar();
    void setMar(std::string mar);
    std::string getMile50();
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

class TeamDataContainer : public FileDataContainer
{
public:
    TeamDataContainer();
    std::string getName();
    void setName(std::string name);
    std::string getAthletes();
    void setAthletes(std::string athletes);
    std::string getMiles();
    void setMiles(std::string miles);
    std::string getPace();
    void setPace(std::string pace);
    std::string getAscent();
    void setAscent(std::string ascent);
    std::string getFastest();
    void setFastest(std::string fastest);
private:
    std::string _name;
    std::string _athletes;
    std::string _miles;
    std::string _pace;
    std::string _ascent;
    std::string _fastest;
};

class RunsDataContainer : public FileDataContainer
{
public:
    RunsDataContainer();
    std::vector <RunDataContainer> getRuns();
    void setRuns(std::vector<RunDataContainer> runs);
private:
    std::vector<RunDataContainer> _runs;
};

class AthletesDataContainer : public FileDataContainer
{
public:
    AthletesDataContainer();
    std::vector <AthleteDataContainer> getAthletes();
    void setAthletes(std::vector<AthleteDataContainer> athletes);
private:
    std::vector<AthleteDataContainer> _athletes;
};

class TeamsDataContainer : public FileDataContainer
{
public:
    TeamsDataContainer();
    std::vector <TeamDataContainer> getTeams();
    void setTeams(std::vector<TeamDataContainer> teams);
private:
    std::vector<TeamDataContainer> _teams;
};



#endif // FILEDATACONTAINER_H
