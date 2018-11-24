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

std::vector<RunDataContainer> RunsDataContainer::get_runs()
{
    return _runs;
}

void RunsDataContainer::set_runs(std::vector<RunDataContainer> runs)
{
    _runs = runs;
}


RunDataContainer::RunDataContainer()
{

}

std::string RunDataContainer::get_date()
{
    return _date;
}

void RunDataContainer::set_date(std::string date)
{
    _date = date;
}

std::string RunDataContainer::get_time()
{
    return _time;
}

void RunDataContainer::set_time(std::__cxx11::string time)
{
    _time = time;
}

std::string RunDataContainer::get_miles()
{
    return _miles;
}

void RunDataContainer::set_miles(std::__cxx11::string miles)
{
    _miles = miles;
}

std::string RunDataContainer::get_egain()
{
    return _egain;
}

void RunDataContainer::set_egain(std::__cxx11::string egain)
{
    _egain = egain;
}

std::string RunDataContainer::get_mhr()
{
    return _mhr;
}

void RunDataContainer::set_mhr(std::__cxx11::string mhr)
{
    _mhr = mhr;
}

std::string RunDataContainer::get_ahr()
{
    return _ahr;
}

void RunDataContainer::set_ahr(std::__cxx11::string ahr)
{
    _ahr = ahr;
}

std::string RunDataContainer::get_cals()
{
    return _cals;
}

void RunDataContainer::set_cals(std::string cals)
{
    _cals = cals;
}

std::string RunDataContainer::get_fastest()
{
    return _fastest;
}

void RunDataContainer::set_fastest(std::string fastest)
{
    _fastest = fastest;
}

std::string RunDataContainer::get_tag()
{
    return _tag;
}

void RunDataContainer::set_tag(std::string tag)
{
    _tag = tag;
}

std::string AthleteDataContainer::get_name()
{
    return _name;
}

void AthleteDataContainer::set_name(std::string name)
{
    _name = name;
}

std::string AthleteDataContainer::get_miles()
{
    return _miles;
}

void AthleteDataContainer::set_miles(std::string miles)
{
    _miles = miles;
}

std::string AthleteDataContainer::get_ytd_miles()
{
    return _ytd_miles;
}

void AthleteDataContainer::set_ytd_miles(std::string ytd_miles)
{
    _ytd_miles = ytd_miles;
}

std::string AthleteDataContainer::get_last_miles()
{
    return _last_miles;
}

void AthleteDataContainer::set_last_miles(std::string last_miles)
{
    _last_miles = last_miles;
}

std::string AthleteDataContainer::get_pace()
{
    return _pace;
}

void AthleteDataContainer::set_pace(std::string pace)
{
    _pace = pace;
}

std::string AthleteDataContainer::get_ytd_pace()
{
    return _ytd_pace;
}

void AthleteDataContainer::set_ytd_pace(std::string ytd_pace)
{
    _ytd_pace = ytd_pace;
}

std::string AthleteDataContainer::get_ascent()
{
    return _ascent;
}

void AthleteDataContainer::set_ascent(std::string ascent)
{
    _ascent = ascent;
}

std::string AthleteDataContainer::get_ytd_ascent()
{
    return _ytd_ascent;
}

void AthleteDataContainer::set_ytd_ascent(std::string ytd_ascent)
{
    _ytd_ascent = ytd_ascent;
}

std::string AthleteDataContainer::get_mile1()
{
    return _mile1;
}

void AthleteDataContainer::set_mile1(std::string mile1)
{
    _mile1 = mile1;
}

std::string AthleteDataContainer::get_mile2()
{
    return _mile2;
}

void AthleteDataContainer::set_mile2(std::string mile2)
{
    _mile2 = mile2;
}

std::string AthleteDataContainer::get_k5()
{
    return _k5;
}

void AthleteDataContainer::set_k5(std::string k5)
{
    _k5 = k5;
}

std::string AthleteDataContainer::get_k10()
{
    return _k10;
}

void AthleteDataContainer::set_k10(std::string k10)
{
    _k10 = k10;
}

std::string AthleteDataContainer::get_half_mar()
{
    return _half_mar;
}

void AthleteDataContainer::set_half_mar(std::string half_mar)
{
    _half_mar = half_mar;
}

std::string AthleteDataContainer::get_mar()
{
    return _mar;
}

void AthleteDataContainer::set_mar(std::string mar)
{
    _mar = mar;
}

std::string AthleteDataContainer::get_mile50()
{
    return _mile50;
}

void AthleteDataContainer::set_mile50(std::string mile50)
{
    _mile50 = mile50;
}

AthleteDataContainer::AthleteDataContainer()
{

}

AthletesDataContainer::AthletesDataContainer()
{

}

std::vector<AthleteDataContainer> AthletesDataContainer::get_athletes()
{
    return _athletes;
}

void AthletesDataContainer::set_athletes(std::vector<AthleteDataContainer> athletes)
{
    _athletes = athletes;
}
