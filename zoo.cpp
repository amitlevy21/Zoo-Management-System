//
// Created by Amit Levy on 08/10/17.
//

#include "zoo.h"
#include <string.h>

Zoo* Zoo::theZoo;

Zoo::Zoo(const char *name, int maxNumOfAreas, Area& quarantineArea): quarantineArea(quarantineArea)
{
    setName(name);
    setMaxNumOfAreas(maxNumOfAreas);

    areas = new Area*[maxNumOfAreas];
}

Zoo::~Zoo()
{
    delete[](name);
}

const char *Zoo::getName() const
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

void Zoo::addArea(Area &area) throw(const char*)
{
    if(findAreaIndex(area) != -1)
    {
        throw "Area already exists in the zoo";
    }
    areas[numOfAreas++] = &area;
}

void Zoo::addAnimal(Animal& animal, Area& area) throw(const char*)
{
    int areaIndex = findAreaIndex(area);

    if(areaIndex == -1)
    {
        throw "Tried to add animal to an Area that was not added to zoo";
    }

    areas[areaIndex]->addAnimal(animal);
}

void Zoo::addWorker(Worker& worker, Area& area) throw(const char*)
{
    int areaIndex = findAreaIndex(area);

    if(areaIndex == - 1)
    {
       throw "Tried to add worker to an Area that was not added to zoo";
    }

    areas[areaIndex]->addWorker(worker);
}

const Area ** Zoo::getAllAreas() const
{
    return (const Area**)areas;
}

Area **Zoo::getAllAreas()
{
    return areas;
}

void Zoo::setMaxNumOfAreas(int maxNumOfAreas) throw(const char*)
{
    if(maxNumOfAreas <= 0)
    {
        throw "ERROR: maxNumOfAreas in Zoo must be greater than 0";
    }

    this->maxNumOfAreas = maxNumOfAreas;
}

void Zoo::setName(const char *name) throw(const char*)
{
    if(!name)
    {
        throw "ERROR: Zoo's name is pointing to NULL";
    }

    if(strcmp(name,"") == 0)
    {
        throw "ERROR: Zoo's name cannot be empty";
    }

    this->name = strdup(name);
}

const Zoo &Zoo::operator+=(Area &area)
{
    addArea(area);
    return *this;
}

const Area &Zoo::operator[](int index) const throw(const char*)
{
    if(index < 0 || index > numOfAreas)
    {
        throw "ERROR: index out of bound in Zoo::areas array";
    }

    return *areas[index];
}

ostream& operator<<(ostream& os, const Zoo& zoo)
{
    os << "Zoo name: " << zoo.getName() << ", area capacity: " << zoo.getMaxNumOfAreas() <<", number of areas: " << zoo.getNumOfAreas() << endl;
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
    for (int i = 0; i < numOfAreas; i++)
    {
        if(*areas[i] == area)
        {
            return i;
        }
    }

    return -1;
}

Zoo *Zoo::getInstance(const char *name, int maxNumOfAreas, Area& quarantineArea)
{
    if(!theZoo)
    {
        theZoo = new Zoo(name, maxNumOfAreas, quarantineArea);
    }
    return theZoo;
}



