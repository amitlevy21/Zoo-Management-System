//
// Created by Moshe Sheena on 07/10/2017.
//

#include "area.h"
#include <string.h>
#include "animal.h"
#include "worker.h"
#include "areaManager.h"
#include "keeper.h"
#include <algorithm>
#include <iterator>


void Area::setMaxNumberOfAnimals(int maxNumberOfAnimals) throw(const string&)
{
    if(maxNumberOfAnimals <= 0)
        throw "area must have at least 1 animal";

    this->maxNumberOfAnimals = maxNumberOfAnimals;
}

void Area::setMaxNumberOfWorkers(int maxNumberOfWorkers) throw(const string&)
{
    if(maxNumberOfWorkers <= 0)
        throw "area must have at least 1 worker";

    this->maxNumberOfWorkers = maxNumberOfWorkers;
}

Area::Area(const string& name, int maxNumberOfAnimals, int maxNumberOfWorkers, Animal::eAnimalClass habitat, AreaManager *areaManager)
        :habitat(habitat), animals(), workers(), observers()
{
    setAreaName(name);
    setMaxNumberOfAnimals(maxNumberOfAnimals);
    setMaxNumberOfWorkers(maxNumberOfWorkers);
    setAreaManager(*areaManager);

    workers.reserve(maxNumberOfWorkers);
    observers.reserve(INITIAL_OBSERVER_NUM);
}

const string& Area::getName() const
{
    return name;
}

int Area::getNumOfAnimals() const
{
    return animals.getSize();
}

int Area::getMaxNumberOfAnimals() const
{
    return maxNumberOfAnimals;
}

int Area::getNumOfWorkers() const
{
    return workers.size();
}

int Area::getMaxNumberOfWorkers() const
{
    return maxNumberOfWorkers;
}

const AreaManager& Area::getAreaManager() const
{
    return *areaManager;
}

void Area::setAreaManager(AreaManager& areaManager)
{
    if((this->areaManager == nullptr) || (this->areaManager != &areaManager))
    {
        if(&areaManager)
        {
            this->areaManager = &areaManager;
            areaManager.setArea(*this);
        }
    }
}

void Area::addAnimal(Animal& animal) throw(const string&)
{
    if(animals.exists(&animal))
        return;

    if(getNumOfAnimals() >= maxNumberOfAnimals)
        throw "zoo animal capacity has been reached.";

    animals.addNodeToBackOfList(&animal);
    animal.setArea(*this);
    notifyAllObservers(animal);
}

void Area::addWorker(Worker& worker) throw(const string&)
{
    vector<Worker*>::iterator found = find(workers.begin(), workers.end(), &worker);
    if(found != workers.end())
        return;

    if(getNumOfWorkers() >= maxNumberOfWorkers)
        throw "zoo worker capacity has been reached.";

    workers.push_back(&worker);
    worker.setArea(*this);

    Keeper* keeper = dynamic_cast<Keeper*>(&worker);
    if(keeper)
        registerObserver(*keeper);
}

const MyLinkedList<Animal*>& Area::getAllAnimals() const
{
    return animals;
}

const vector<Worker*>& Area::getAllWorkers() const
{
    return workers;
}

const Area& Area::operator+=(Animal &animal)
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
    return name == other.getName();
}

ostream &operator<<(ostream &os, const Area& area)
{
    os << "Area name: " << area.name.c_str() << ", habitat: " << animalClasses[static_cast<int>(area.getHabitat())] << ", number of animals: " << area.getNumOfAnimals()
       << ", up to: " << area.maxNumberOfAnimals << ", number of workers: "
       << area.getNumOfWorkers() << ", up to: " << area.maxNumberOfWorkers
       << ", managed by: " << area.areaManager->getName().c_str() << endl;

    os << "The animals:" << endl;

    if(area.getNumOfAnimals() > 0)
    {
        //area.animals.printList(os); //prints animals addresses
        for (int i = 0; i < area.getNumOfAnimals(); i++)
        {
            cout << *area.animals[i] << endl;
        }
    }
    else
    {
        os << "no animals are found" << endl;
    }


    os << "The workers:" << endl;

    if(area.getNumOfWorkers() > 0)
    {
        for (int i = 0; i < area.getNumOfWorkers(); ++i)
        {
            cout << *area.workers[i] << endl;
        }
    }
    else
    {
        os << "no workers found.";
    }

    return os;
}

void Area::setAreaName(const string& name)
{
    if(name.empty())
    {
        throw "worker's name cannot be empty";
    }

    this->name = name;
}

Area::~Area()
{
    workers.clear();
    observers.clear();
}

Animal::eAnimalClass Area::getHabitat() const
{
    return habitat;
}

void Area::registerObserver(Observer& obs)
{
    observers.push_back(&obs);
}

void Area::notifyAllObservers(const Animal &animalAdded)
{
    vector<Observer*>::iterator itr = observers.begin();
    vector<Observer*>::iterator itrEnd = observers.end();

    for (; itr != itrEnd; ++itr)
        (*itr)->notify(animalAdded);
}
