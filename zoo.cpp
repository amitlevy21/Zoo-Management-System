//
// Created by Amit Levy on 08/10/17.
//

#include "Zoo.h"
#include <string.h>



Zoo::Zoo(const char *name, int maxNumOfAreas, Area& quarantineArea): quarantineArea(quarantineArea)
{
    setMaxNumOfAreas(maxNumOfAreas);
    setName(name);

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
    return <#initializer#>;
}

void Zoo::addArea(Area &area)
{
    if(findAreaIndex(area) != -1)
    {
        throw "Area already exists in the zoo";
    }
    areas[numOfAreas] = &area;
    numOfAreas++;
}

void Zoo::addAnimal(Animal& animal, Area& area)
{
    int areaIndex = findAreaIndex(area);

    if(areaIndex == -1)
    {
        throw "Tried to add animal to an Area that was not added to zoo";
    }

    areas[areaIndex]->addAnimal(animal);
}

void Zoo::addWorker(Worker& worker, Area& area)
{
    int areaIndex = findAreaIndex(area);

    if(areaIndex == - 1)
    {
       throw "Tried to add worker to an Area that was not added to zoo";
    }

    areas[areaIndex]->addWorker(worker);
}

const Area **Zoo::getAllAreas() const
{
    return (const Area**)areas;
}

void Zoo::setMaxNumOfAreas(int maxNumOfAreas)
{
    if(maxNumOfAreas <= 0)
    {
        throw "ERROR: maxNumOfAreas in Zoo must be greater than 0";
    }

    this->maxNumOfAreas = maxNumOfAreas;
}

void Zoo::setName(const char *name)
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
}

const Area &Zoo::operator[](int index) const
{
    if(index < 0 || index > numOfAreas)
    {
        throw "ERROR: index out of bound in Zoo::areas array";
    }

    return *areas[index];
}

ostream& operator<<(ostream& os, const Zoo& zoo)
{
    os << "Zoo Details:\nName: " << name << "\nArea Capacity: " << maxNumOfAreas <<"\nNum of Areas: " << numOfAreas << endl;
    for (int i = 0; i < numOfAreas; ++i)
    {
        os << areas[i];
    }
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

