//
// Created by Moshe Sheena on 07/10/2017.
//

#include "area.h"
#include <string.h>
#include "animal.h"
#include "worker.h"
#include "areaManager.h"
#include "keeper.h"


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
        :habitat(habitat), animals()
{
    setAreaName(name);
    setMaxNumberOfAnimals(maxNumberOfAnimals);
    setMaxNumberOfWorkers(maxNumberOfWorkers);
    setAreaManager(*areaManager);

    workers.reserve(maxNumberOfWorkers);
}

const string& Area::getName() const
{
    return name;
}

int Area::getNumOfAnimals() const
{
    return numOfAnimals;
}

int Area::getMaxNumberOfAnimals() const
{
    return maxNumberOfAnimals;
}

int Area::getNumOfWorkers() const
{
    return numOfWorkers;
}

int Area::getMaxNumberOfWorkers() const
{
    return maxNumberOfWorkers;
}

const AreaManager &Area::getAreaManager() const
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
    for (int i = 0; i < numOfAnimals; i++)
        if(animals.exists(&animal))
            return;

    if(numOfAnimals >= maxNumberOfAnimals)
        throw "zoo animal capacity has been reached.";

    animals.addNodeToBackOfList(&animal);
    numOfAnimals++;
    animal.setArea(*this);
    notifyAllObservers(animal);
}

void Area::addWorker(Worker& worker) throw(const string&)
{
    for (int i = 0; i < numOfWorkers; ++i)
        if(*workers[i] == worker)
            return;

    if(numOfWorkers >= maxNumberOfWorkers)
        throw "zoo worker capacity has been reached.";

    workers.push_back(&worker);
    numOfWorkers++;
    worker.setArea(*this);

    Keeper* keeper = dynamic_cast<Keeper*>(&worker);
    if(keeper)
        registerObserver(keeper);
}

const MyLinkedList<Animal*>& Area::getAllAnimals() const
{
    return animals;
}

const vector<Worker*> Area::getAllWorkers() const
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
    os << "Area name: " << area.name.c_str() << ", habitat: " << animalClasses[static_cast<int>(area.getHabitat())] << ", number of animals: " << area.numOfAnimals
       << ", up to: " << area.maxNumberOfAnimals << ", number of workers: "
       << area.numOfWorkers << ", up to: " << area.maxNumberOfWorkers
       << ", managed by: " << area.areaManager->getName().c_str() << endl;

    os << "The animals:" << endl;

    if(area.numOfAnimals > 0)
    {
        for (int i = 0; i < area.numOfAnimals; i++)
        {
            os << i + 1 << ") " << *(area.animals[i]) << endl;
        }
    }
    else
    {
        os << "no animals are found" << endl;
    }


    os << "The workers:" << endl;

    if(area.numOfWorkers > 0)
    {
        for (int i = 0; i < area.getNumOfWorkers(); ++i)
        {
            os << i + 1 << ") " << *area.getAllWorkers()[i] << endl;
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
    if(name == "")
    {
        throw "ERROR: worker's name cannot be empty";
    }
    this->name = name;
}

Area::~Area()
{
    workers.clear();
}

Animal::eAnimalClass Area::getHabitat() const
{
    return habitat;
}

int Area::getNumOfSpacesLeftInAreaForAnimals() const
{
    return maxNumberOfAnimals - numOfAnimals;
}

void Area::registerObserver(Observer *obs)
{
    if(numOfObservers < MAX_NUM_OF_OBSERVERS)
    {
        observers[numOfObservers] = obs;
        numOfObservers++;
    }
}

void Area::notifyAllObservers(Animal &animalAdded)
{
    for (int i = 0; i < numOfObservers; ++i)
    {
        observers[i]->notify(animalAdded);
    }
}
