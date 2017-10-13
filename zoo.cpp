//
// Created by Amit Levy on 08/10/17.
//

#include "zoo.h"
#include <string.h>

Zoo* Zoo::theZoo;

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
    return numOfAreas;
}

const Area &Zoo::getQuarantineAreaArea() const
{
    return quarantineArea;
}

void Zoo::addArea(Area &area) throw(const string&)
{
    if(findAreaIndex(area) != -1)
    {
        throw "Area already exists in the zoo";
    }
    areas.push_back(&area);
}

void Zoo::addAnimal(Animal& animal, Area& area) throw(const string&)
{
    int areaIndex = findAreaIndex(area);

    if(areaIndex == -1)
    {
        throw "Tried to add animal to an Area that was not added to zoo";
    }

    vector<Area*>::iterator itr = areas.begin();
    itr += areaIndex;
    (*itr)->addAnimal(animal);
}

void Zoo::addWorker(Worker& worker, Area& area) throw(const string&)
{
    int areaIndex = findAreaIndex(area);

    if(areaIndex == - 1)
    {
       throw "Tried to add worker to an Area that was not added to zoo";
    }

    areas[areaIndex]->addWorker(worker);
}

const vector<Area*> Zoo::getAllAreas() const
{
    return areas;
}

vector<Area*> Zoo::getAllAreas()
{
    return areas;
}

void Zoo::setMaxNumOfAreas(int maxNumOfAreas) throw(const string&)
{
    if(maxNumOfAreas <= 0)
    {
        throw "ERROR: maxNumOfAreas in Zoo must be greater than 0";
    }

    this->maxNumOfAreas = maxNumOfAreas;
}

void Zoo::setName(const string& name) throw(const string&)
{
    if(name == "")
    {
        throw "ERROR: Zoo's name cannot be empty";
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
    if(index < 0 || index > numOfAreas)
    {
        throw "ERROR: index out of bound in Zoo::areas array";
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
    for (int i = 0; i < zoo.getNumOfAreas(); i++)
    {
        os << *(zoo.getAllAreas()[i]) << endl;
        os << "-----------------" << endl;
    }
    return os;
}

int Zoo::findAreaIndex(const Area &area) const
{
    vector<Area*>::const_iterator itr = areas.begin();
    vector<Area*>::const_iterator itrEnd = areas.begin();

    for (int i = 0; itr != itrEnd; ++itr, ++i)
    {
        if(*(*itr) == area)
        {
            return i;
        }
    }

    return -1;
}

Zoo *Zoo::getInstance(const string& name, int maxNumOfAreas, Area& quarantineArea)
{
    if(!theZoo)
    {
        theZoo = new Zoo(name, maxNumOfAreas, quarantineArea);
    }
    return theZoo;
}



