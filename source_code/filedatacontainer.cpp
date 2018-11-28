#include "filedatacontainer.h"

FileDataContainer::FileDataContainer()
{

}

CredentialsDataContainer::CredentialsDataContainer()
{

}

void CredentialsDataContainer::setUsername(std::__cxx11::string username)
{
    _username = username;
}

void CredentialsDataContainer::setPassword(std::__cxx11::string password)
{
    _password = password;
}

std::string CredentialsDataContainer::getPassword()
{
    return _password;
}

std::string CredentialsDataContainer::getUsername()
{
    return _password;
}

RunsDataContainer::RunsDataContainer()
{

}

std::vector<RunDataContainer> RunsDataContainer::getRuns()
{
    return _runs;
}

void RunsDataContainer::setRuns(std::vector<RunDataContainer> runs)
{
    _runs = runs;
}


RunDataContainer::RunDataContainer()
{

}

std::string RunDataContainer::getDate()
{
    return _date;
}

void RunDataContainer::setDate(std::string date)
{
    _date = date;
}

std::string RunDataContainer::getTime()
{
    return _time;
}

void RunDataContainer::setTime(std::__cxx11::string time)
{
    _time = time;
}

std::string RunDataContainer::getMiles()
{
    return _miles;
}

void RunDataContainer::setMiles(std::__cxx11::string miles)
{
    _miles = miles;
}

std::string RunDataContainer::getEgain()
{
    return _egain;
}

void RunDataContainer::setEgain(std::__cxx11::string egain)
{
    _egain = egain;
}

std::string RunDataContainer::getMhr()
{
    return _mhr;
}

void RunDataContainer::setMhr(std::__cxx11::string mhr)
{
    _mhr = mhr;
}

std::string RunDataContainer::getAhr()
{
    return _ahr;
}

void RunDataContainer::setAhr(std::__cxx11::string ahr)
{
    _ahr = ahr;
}

std::string RunDataContainer::getCals()
{
    return _cals;
}

void RunDataContainer::setCals(std::string cals)
{
    _cals = cals;
}

std::string RunDataContainer::getFastest()
{
    return _fastest;
}

void RunDataContainer::setFastest(std::string fastest)
{
    _fastest = fastest;
}

std::string RunDataContainer::getTag()
{
    return _tag;
}

void RunDataContainer::setTag(std::string tag)
{
    _tag = tag;
}

std::string AthleteDataContainer::getName()
{
    return _name;
}

void AthleteDataContainer::setName(std::string name)
{
    _name = name;
}

std::string AthleteDataContainer::getMiles()
{
    return _miles;
}

void AthleteDataContainer::setMiles(std::string miles)
{
    _miles = miles;
}

std::string AthleteDataContainer::getYtdMiles()
{
    return _ytdMiles;
}

void AthleteDataContainer::setYtdMiles(std::string ytd_miles)
{
    _ytdMiles = ytd_miles;
}

std::string AthleteDataContainer::getLastMiles()
{
    return _lastMiles;
}

void AthleteDataContainer::setLastMiles(std::string lastMiles)
{
    _lastMiles = lastMiles;
}

std::string AthleteDataContainer::getPace()
{
    return _pace;
}

void AthleteDataContainer::setPace(std::string pace)
{
    _pace = pace;
}

std::string AthleteDataContainer::getYtdPace()
{
    return _ytdPace;
}

void AthleteDataContainer::setYtdPace(std::string ytdPace)
{
    _ytdPace = ytdPace;
}

std::string AthleteDataContainer::getAscent()
{
    return _ascent;
}

void AthleteDataContainer::setAscent(std::string ascent)
{
    _ascent = ascent;
}

std::string AthleteDataContainer::getYtdAscent()
{
    return _ytdAscent;
}

void AthleteDataContainer::setYtdAscent(std::string ytdAscent)
{
    _ytdAscent = ytdAscent;
}

std::string AthleteDataContainer::getMile1()
{
    return _mile1;
}

void AthleteDataContainer::setMile1(std::string mile1)
{
    _mile1 = mile1;
}

std::string AthleteDataContainer::getMile2()
{
    return _mile2;
}

void AthleteDataContainer::setMile2(std::string mile2)
{
    _mile2 = mile2;
}

std::string AthleteDataContainer::getK5()
{
    return _k5;
}

void AthleteDataContainer::setK5(std::string k5)
{
    _k5 = k5;
}

std::string AthleteDataContainer::getK10()
{
    return _k10;
}

void AthleteDataContainer::setK10(std::string k10)
{
    _k10 = k10;
}

std::string AthleteDataContainer::getHalfMar()
{
    return _halfMar;
}

void AthleteDataContainer::setHalfMar(std::string halfMar)
{
    _halfMar = halfMar;
}

std::string AthleteDataContainer::getMar()
{
    return _mar;
}

void AthleteDataContainer::setMar(std::string mar)
{
    _mar = mar;
}

std::string AthleteDataContainer::getMile50()
{
    return _mile50;
}

void AthleteDataContainer::setMile50(std::string mile50)
{
    _mile50 = mile50;
}

AthleteDataContainer::AthleteDataContainer()
{

}

AthletesDataContainer::AthletesDataContainer()
{

}

std::vector<AthleteDataContainer> AthletesDataContainer::getAthletes()
{
    return _athletes;
}

void AthletesDataContainer::setAthletes(std::vector<AthleteDataContainer> athletes)
{
    _athletes = athletes;
}

TeamsDataContainer::TeamsDataContainer()
{

}

std::vector<TeamDataContainer> TeamsDataContainer::getTeams()
{
    return _teams;
}

void TeamsDataContainer::setTeams(std::vector<TeamDataContainer> teams)
{
    _teams = teams;
}

std::string TeamDataContainer::getName()
{
    return _name;
}

void TeamDataContainer::setName(std::string name)
{
    _name = name;
}

std::string TeamDataContainer::getAthletes()
{
    return _athletes;
}

void TeamDataContainer::setAthletes(std::string athletes)
{
    _athletes = athletes;
}

std::string TeamDataContainer::getMiles()
{
    return _miles;
}

void TeamDataContainer::setMiles(std::string miles)
{
    _miles = miles;
}

std::string TeamDataContainer::getPace()
{
    return _pace;
}

void TeamDataContainer::setPace(std::string pace)
{
    _pace = pace;
}

std::string TeamDataContainer::getAscent()
{
    return _ascent;
}

void TeamDataContainer::setAscent(std::string ascent)
{
    _ascent = ascent;
}

std::string TeamDataContainer::getFastest()
{
    return _fastest;
}

void TeamDataContainer::setFastest(std::string fastest)
{
    _fastest = fastest;
}

TeamDataContainer::TeamDataContainer()
{

}
