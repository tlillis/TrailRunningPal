#include "filedatacontainer.h"

FileDataContainer::FileDataContainer()
{

}

CredentialsDataContainer::CredentialsDataContainer()
{

}

void CredentialsDataContainer::set_username(std::__cxx11::string username)
{
    _username = username;
}

void CredentialsDataContainer::set_password(std::__cxx11::string password)
{
    _password = password;
}

std::string CredentialsDataContainer::get_password()
{
    return _password;
}

std::string CredentialsDataContainer::get_username()
{
    return _password;
}

RunsDataContainer::RunsDataContainer()
{

}

std::vector<RunData> RunsDataContainer::get_runs()
{
    return _runs;
}

void RunsDataContainer::set_runs(std::vector<RunData> runs)
{
    _runs = runs;
}


RunData::RunData()
{

}

std::string RunData::get_date()
{
    return _date;
}

void RunData::set_date(std::string date)
{
    _date = date;
}

std::string RunData::get_time()
{
    return _time;
}

void RunData::set_time(std::__cxx11::string time)
{
    _time = time;
}

std::string RunData::get_miles()
{
    return _miles;
}

void RunData::set_miles(std::__cxx11::string miles)
{
    _miles = miles;
}

std::string RunData::get_egain()
{
    return _egain;
}

void RunData::set_egain(std::__cxx11::string egain)
{
    _egain = egain;
}

std::string RunData::get_mhr()
{
    return _mhr;
}

void RunData::set_mhr(std::__cxx11::string mhr)
{
    _mhr = mhr;
}

std::string RunData::get_ahr()
{
    return _ahr;
}

void RunData::set_ahr(std::__cxx11::string ahr)
{
    _ahr = ahr;
}

std::string RunData::get_cals()
{
    return _cals;
}

void RunData::set_cals(std::string cals)
{
    _cals = cals;
}

std::string RunData::get_fastest()
{
    return _fastest;
}

void RunData::set_fastest(std::string fastest)
{
    _fastest = fastest;
}

std::string RunData::get_tag()
{
    return _tag;
}

void RunData::set_tag(std::string tag)
{
    _tag = tag;
}
