#include "zoo.h"
#include <algorithm>

Zoo* Zoo::theZoo = nullptr;

Zoo::Zoo(const string& name, int maxNumOfAreas, Area& quarantineArea): quarantineArea(quarantineArea)
{
    setName(name);
    setMaxNumOfAreas(maxNumOfAreas);

    areas.reserve(maxNumOfAreas);
}

const string& Zoo::getName() const
{
    return name;
}

int Zoo::getMaxNumOfAreas() const
{
    return maxNumOfAreas;
}

int Zoo::getNumOfAreas() const
{
    return areas.size();
}

const Area& Zoo::getQuarantineArea() const
{
    return quarantineArea;
}

void Zoo::addArea(Area &area) throw(const string&)
{
    if(existsArea(area))
    {
        throw "Area already exists in the zoo";
    }
    areas.push_back(&area);
}

void Zoo::addAnimal(Animal& animal, Area& area) throw(const string&)
{
    if(!existsArea(area))
    {
        throw "Tried to add animal to an Area that was not added to zoo";
    }

    area.addAnimal(animal);
}

void Zoo::addWorker(Worker& worker, Area& area) throw(const string&)
{
    if(!existsArea(area))
    {
       throw "Tried to add worker to an Area that was not added to zoo";
    }

    area.addWorker(worker);
}

const vector<Area*>& Zoo::getAllAreas() const
{
    return areas;
}

vector<Area*>& Zoo::getAllAreas()
{
    return areas;
}

void Zoo::setMaxNumOfAreas(int maxNumOfAreas) throw(const string&)
{
    if(maxNumOfAreas <= 0)
    {
        throw "maxNumOfAreas in Zoo must be greater than 0";
    }

    this->maxNumOfAreas = maxNumOfAreas;
}

void Zoo::setName(const string& name) throw(const string&)
{
    if(name.empty())
    {
        throw "Zoo's name cannot be empty";
    }

    this->name = name;
}

const Zoo &Zoo::operator+=(Area &area)
{
    addArea(area);
    return *this;
}

const Area& Zoo::operator[](int index) const throw(const string&)
{
    if(index < 0 || index > areas.size())
    {
        throw "index out of bound";
    }

    vector<Area*>::const_iterator itr = areas.begin();
    itr += index;
    return *(*itr);
}

ostream& operator<<(ostream& os, const Zoo& zoo)
{
    os << "Zoo name: " << zoo.getName().c_str() << ", area capacity: " << zoo.getMaxNumOfAreas() <<", number of areas: " << zoo.getNumOfAreas() << endl;
    os << "Areas: " << endl;
    os << "-----------------" << endl;
    for (int i = 0; i < zoo.getNumOfAreas(); ++i)
    {
        os << *(zoo.getAllAreas()[i]) << endl;
        os << "-----------------" << endl;
    }
    return os;
}

Zoo *Zoo::getInstance(const string& name, int maxNumOfAreas, Area& quarantineArea)
{
    if(!theZoo)
    {
        theZoo = new Zoo(name, maxNumOfAreas, quarantineArea);
    }
    return theZoo;
}

Zoo::~Zoo()
{
    areas.clear();
}

bool Zoo::existsArea(const Area &area) const
{
    vector<Area*>::const_iterator found = find(areas.begin(), areas.end(), &area);
    if(found == areas.end())
        return false;

    return true;
}



