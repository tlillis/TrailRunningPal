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

class RunData
{
public:
    RunData();
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
    /**
    unsigned int get_time();
    void set_time(unsigned int time);
    float get_miles();
    void set_miles(float miles);
    float get_egain();
    void set_egain(float egain);
    unsigned int get_mhr();
    void set_mhr(unsigned int mhr);
    unsigned int get_ahr();
    void set_ahr(unsigned int ahr);
    unsigned int get_cals();
    void set_cals(unsigned int cals);
    unsigned int get_fastest();
    void set_fastest(unsigned int fastest);
    **/
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
    /**
    unsigned int _time;
    float _miles;
    float _egain;
    unsigned int _mhr;
    unsigned int _ahr;
    unsigned int _cals;
    unsigned int _fastest;
    **/
    std::string _tag;
};

class RunsDataContainer : public FileDataContainer
{
public:
    RunsDataContainer();
    std::vector <RunData> get_runs();
    void set_runs(std::vector<RunData> runs);
private:
    std::vector<RunData> _runs;
};



#endif // FILEDATACONTAINER_H
