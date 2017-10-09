//
// Created by Moshe Sheena on 07/10/2017.
//

#include "area.h"
#include <string.h>
#include "animal.h"
#include "worker.h"
#include "areaManager.h"

void Area::setMaxNumberOfAnimals(int maxNumberOfAnimals) throw(const char*)
{
    if(maxNumberOfAnimals <= 0)
        throw "area must have at least 1 animal";

    this->maxNumberOfAnimals = maxNumberOfAnimals;
}

void Area::setMaxNumberOfWorkers(int maxNumberOfWorkers) throw(const char*)
{
    if(maxNumberOfWorkers <= 0)
        throw "area must have at least 1 worker";

    this->maxNumberOfWorkers = maxNumberOfWorkers;
}

Area::Area(const char *name, int maxNumberOfAnimals, int maxNumberOfWorkers, eAnimalClass habitat, AreaManager *areaManager)
        :habitat(habitat)
{
    setAreaName(name);
    setMaxNumberOfAnimals(maxNumberOfAnimals);
    setMaxNumberOfWorkers(maxNumberOfWorkers);
    setAreaManager(*areaManager);

    animals = new Animal*[maxNumberOfAnimals];
    workers = new Worker*[maxNumberOfWorkers];
}

const char *Area::getName() const
{
    return name;
}

long Area::getNumOfAnimals() const
{
    return numOfAnimals;
}

long Area::getMaxNumberOfAnimals() const
{
    return maxNumberOfAnimals;
}

long Area::getNumOfWorkers() const
{
    return numOfWorkers;
}

long Area::getMaxNumberOfWorkers() const
{
    return maxNumberOfWorkers;
}

const AreaManager &Area::getAreaManager() const
{
    return *areaManager;
}

void Area::setAreaManager(AreaManager &areaManager)
{
    if(this->areaManager != &areaManager)
    {
        this->areaManager = &areaManager;
        areaManager.setArea(*this);
    }
}

void Area::addAnimal(Animal& animal) throw(const char*)
{
    for (int i = 0; i < numOfAnimals; i++)
        if(*animals[i] == animal)
            return;

    if(numOfAnimals >= maxNumberOfAnimals)
        throw "zoo animal capacity has been reached.";

    animals[numOfAnimals++] = &animal;
    animal.setArea(*this);
}

void Area::addWorker(Worker& worker) throw(const char*)
{
    for (int i = 0; i < numOfWorkers; i++)
        if(*workers[i] == worker)
            return;

    if(numOfWorkers >= maxNumberOfWorkers)
        throw "zoo worker capacity has been reached.";

    workers[numOfWorkers++] = &worker;
    worker.setArea(*this);
}

const Animal** Area::getAllAnimals() const
{
    return (const Animal**)animals;
}

const Worker **Area::getAllworkers() const
{
    return (const Worker**)workers;
}

const Area &Area::operator+=(Animal &animal)
{
    addAnimal(animal);
    return *this;
}

bool Area::operator<(const Area& other) const
{
    return this->maxNumberOfAnimals < other.getMaxNumberOfAnimals();

}

bool Area::operator>(const Area& other) const
{
    return this->maxNumberOfAnimals > other.getMaxNumberOfAnimals();

}

bool Area::operator==(const Area& other) const
{
    return this->maxNumberOfAnimals == other.maxNumberOfAnimals;

}

ostream &operator<<(ostream &os, const Area& area)
{
    os << "Area name: " << area.name << "habitat: " << animalClasses[area.habitat] << ", number of animals: " << area.numOfAnimals
       << " up to: " << area.maxNumberOfAnimals << ", number of workers: "
       << area.numOfWorkers << " up to: " << area.maxNumberOfWorkers
       << ", managed by: " << area.areaManager->getName() << endl;

    os << "The animals:" << endl;

    for (int i = 0; i < area.numOfAnimals; i++)
    {
        os << i + 1 << ") " << area.animals[i];
    }

    os << endl;

    os << "The workers:" << endl;

    for (int i = 0; i < area.numOfWorkers; i++)
    {
        os << i + 1 << ") " << area.workers[i];
    }

    return os;
}

void Area::setAreaName(const char *name)
{
    if(!name)
    {
        throw "ERROR: worker's name is pointing to NULL";
    }

    if(strcmp(name,"") == 0)
    {
        throw "ERROR: worker's name cannot be empty";
    }
    this->name = strdup(name);
}

Area::~Area()
{
    for (int i = 0; i < numOfAnimals; i++)
    {
        delete(animals[i]);
    }

    for (int j = 0; j < numOfWorkers; j++)
    {
        delete(workers[j]);
    }

    delete[](animals);
    delete[](workers);
}

eAnimalClass Area::getHabitat() const
{
    return habitat;
}
