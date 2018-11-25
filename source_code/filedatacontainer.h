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
    std::string file_type;
};

class CredentialsDataContainer : public FileDataContainer
{
public:
    CredentialsDataContainer();
    std::string get_username();
    void set_username(std::string username);
    std::string get_password();
    void set_password(std::string password);
private:
    std::string _username;
    std::string _password;
};

class RunDataContainer : public FileDataContainer
{
public:
    RunDataContainer();
    std::string get_date();
    void set_date(std::string date);
    std::string get_time();
    void set_time(std::string time);
    std::string get_miles();
    void set_miles(std::string miles);
    std::string get_egain();
    void set_egain(std::string egain);
    std::string get_mhr();
    void set_mhr(std::string mhr);
    std::string get_ahr();
    void set_ahr(std::string ahr);
    std::string get_cals();
    void set_cals(std::string cals);
    std::string get_fastest();
    void set_fastest(std::string fastest);
    std::string get_tag();
    void set_tag(std::string tag);
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
    std::string get_name();
    void set_name(std::string name);
    std::string get_miles();
    void set_miles(std::string miles);
    std::string get_ytd_miles();
    void set_ytd_miles(std::string ytd_miles);
    std::string get_last_miles();
    void set_last_miles(std::string last_miles);
    std::string get_pace();
    void set_pace(std::string pace);
    std::string get_ytd_pace();
    void set_ytd_pace(std::string ytd_pace);
    std::string get_ascent();
    void set_ascent(std::string ascent);
    std::string get_ytd_ascent();
    void set_ytd_ascent(std::string ytd_ascent);
    std::string get_mile1();
    void set_mile1(std::string mile1);
    std::string get_mile2();
    void set_mile2(std::string mile2);
    std::string get_k5();
    void set_k5(std::string k5);
    std::string get_k10();
    void set_k10(std::string k10);
    std::string get_half_mar();
    void set_half_mar(std::string half_mar);
    std::string get_mar();
    void set_mar(std::string mar);
    std::string get_mile50();
    void set_mile50(std::string mile50);
private:
    std::string _name;
    std::string _miles;
    std::string _ytd_miles;
    std::string _last_miles;
    std::string _pace;
    std::string _ytd_pace;
    std::string _ascent;
    std::string _ytd_ascent;
    std::string _mile1;
    std::string _mile2;
    std::string _k5;
    std::string _k10;
    std::string _half_mar;
    std::string _mar;
    std::string _mile50;
};

class TeamDataContainer : public FileDataContainer
{
public:
    TeamDataContainer();
    std::string get_name();
    void set_name(std::string name);
    std::string get_athletes();
    void set_athletes(std::string athletes);
    std::string get_miles();
    void set_miles(std::string miles);
    std::string get_pace();
    void set_pace(std::string pace);
    std::string get_ascent();
    void set_ascent(std::string ascent);
    std::string get_fastest();
    void set_fastest(std::string fastest);
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
    std::vector <RunDataContainer> get_runs();
    void set_runs(std::vector<RunDataContainer> runs);
private:
    std::vector<RunDataContainer> _runs;
};

class AthletesDataContainer : public FileDataContainer
{
public:
    AthletesDataContainer();
    std::vector <AthleteDataContainer> get_athletes();
    void set_athletes(std::vector<AthleteDataContainer> athletes);
private:
    std::vector<AthleteDataContainer> _athletes;
};

class TeamsDataContainer : public FileDataContainer
{
public:
    TeamsDataContainer();
    std::vector <TeamDataContainer> get_teams();
    void set_teams(std::vector<TeamDataContainer> teams);
private:
    std::vector<TeamDataContainer> _teams;
};



#endif // FILEDATACONTAINER_H
