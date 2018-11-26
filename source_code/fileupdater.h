#ifndef FILEUPDATER_H
#define FILEUPDATER_H

#include "athlwindow.h"
#include "coachwindow.h"
#include "loadfile.h"

#include <iostream>
#include <string>
#include <vector>

class Observer
{
public:
    virtual void update(std::string username) = 0;
};

class FileUpdater
{
private:
    std::vector <class Observer *> _obs;
public:
    int clear(std::string filename);
    int write(std::string filename, std::__cxx11::string file_type, std::string content);
    int notify(std::__cxx11::string username);
    int attach(Observer *obs);
    FileUpdater();
};

class AthleteObserver: public Observer {
private:
    AthlWindow * _window = NULL;
public:
    void use_window(AthlWindow * window);
    void update(std::string username);
};

class CoachObserver: public Observer {
private:
    CoachWindow * _window = NULL;
public:
    void use_window(CoachWindow * window);
    void update(std::string username);
};

#endif // FILEUPDATER_H