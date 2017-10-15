#include "zooManager.h"
#include "area.h"
#include "animal.h"
#include "worker.h"
#include "areaManager.h"
#include "veterinarian.h"
#include "keeper.h"
#include "maintenanceWorker.h"
#include "elephant.h"
#include "giraffe.h"
#include "horse.h"
#include "lion.h"
#include "penguin.h"
#include "zebra.h"
#include "zebroid.h"

ZooManager::ZooManager(Zoo &myZoo)
{
    theZoo = &myZoo;
}

vector<AreaManager*>& ZooManager::createAreaManagers(int numOfManagers)
{
    numOfManagers = 3;
    const char* managersNames[] = { "Yogev", "Moshe", "Roie" };
    int managersSalary[] = { 5000, 4500, 4800 };
    int managersYearsOfExperience[] = { 2, 3, 4 };

    vector<AreaManager*>* managers = new vector<AreaManager*>();
    managers->reserve(numOfManagers);

    for (int i = 0; i < numOfManagers; ++i)
    {
        try
        {
            AreaManager* manager = new AreaManager(managersNames[i], managersSalary[i], managersYearsOfExperience[i]);
            managers->push_back(manager);
        }
        catch (const string& errMessage)
        {
            cout << "Could not create manager " << managersNames[i] << ":" << endl << errMessage << endl << endl;
            (*managers)[i] = nullptr;
            break;
        }
    }
    return *managers;
}

vector<Area*>& ZooManager::createAllAreas(int numOfAreas, vector<AreaManager*>& managers)
{
    numOfAreas = 3;
    int maxNumberOfAnimals = 4, maxNumberOfWorkers = 4, wrongMaxNumberOfAnimals = -5;
    const string areasNames[] = { "A1", "A2", "A3" };
    Animal::eAnimalClass classes[] = {Animal::eAnimalClass::LAND, Animal::eAnimalClass::MARINE, Animal::eAnimalClass::AMPHIBIAN};

    vector<Area*>* areas = new vector<Area*>();
    areas->reserve(numOfAreas);

    for (int i = 0; i < numOfAreas; i++)
    {
        try
        {
            Area* area = new Area(areasNames[i], maxNumberOfAnimals, maxNumberOfWorkers, classes[i], managers[i]);
            areas->push_back(area);
        }
        catch (const string& errMessage)
        {
            cout << "Could not create area " << areasNames[i] << ":" << endl << errMessage << endl << endl;
            (*areas)[i] = nullptr;
            break;
        }
    }
    return *areas;
}

void ZooManager::addAreasToZoo(vector<Area*>& areas, int numOfAreas)
{
    for (int i = 0; i < numOfAreas; ++i)
    {
        try
        {
            theZoo->addArea(*areas[i]);
        }
        catch (const string& errMessage)
        {
            cout << "Area " << areas[i]->getName() << " was not added to the zoo:" << endl << errMessage << endl << endl;
        }
    }
}

vector<Animal*>& ZooManager::createAnimals(int numOfAnimals)
{
    numOfAnimals = 4;
    const string names[] = { "Horsy", "Pini", "Eli", "Zeze" };

    vector<Animal*>* animals = new vector<Animal*>();
    animals->reserve(numOfAnimals);

    for (int i = 0; i < numOfAnimals; ++i)
    {
        try
        {
            switch (i%numOfAnimals)
            {
                case 0:
                {
                    Animal* horse = new Horse(names[i], 208.5f, 1998, 40.2f, Animal::eAnimalClass::LAND);
                    animals->push_back(horse);
                    break;
                }
                case 1:
                {
                    Animal* penguin = new Penguin(names[i], 1.2f, 2005, Penguin::CRAB, Animal::eAnimalClass::AMPHIBIAN);
                    animals->push_back(penguin);
                    break;
                }
                case 2:
                {
                    Animal* elephant = new Elephant(names[i], 2.5f, 2000, 1.35f, 2.75f, Animal::eAnimalClass::LAND);
                    animals->push_back(elephant);
                    break;
                }
                case 3:
                {
                    Animal* zebroid = new Zebroid(names[i], 1.45f, 2010, 128, 38.6f, Animal::eAnimalClass::LAND);
                    animals->push_back(zebroid);
                    break;
                }
            }
        }
        catch (const string& errMessage)
        {
            cout << "Could not create animal " << names[i] << ":" << endl << errMessage << endl << endl;
            (*animals)[i] = nullptr;
            break;
        }
    }
    return *animals;
}

void ZooManager::addAllAnimalsToZoo(vector<Animal*>& animals, int numOfAnimals)
{
    int numOfAreas = theZoo->getNumOfAreas();
    vector<Area*>* areas = &theZoo->getAllAreas();

    for (int i = 0; i < numOfAnimals && i < numOfAreas; ++i)
    {
        try
        {
            theZoo->addAnimal(*animals[i], *((*areas)[i]));
        }
        catch (const string& errMessage)
        {
            cout << "Could not add " << animals[i]->getName() << ":" << endl << errMessage << endl << endl;
        }
    }

    // another animal to the last area
    theZoo->addAnimal(*animals[3], *((*areas)[2]));
}

vector<Keeper*>& ZooManager::createAllKeepers(int numOfKeepers)
{
    numOfKeepers = 3;
    const string keepersNames[] = { "Kipi", "Keepi", "Keepee" };
    int keeperSalary = 7500;
    Keeper::eAnimalSpeciality animals[] = { Keeper::HORSE, Keeper::ELEPHANT, Keeper::HORSE };

    vector<Keeper*>* keepers = new vector<Keeper*>();
    keepers->reserve(numOfKeepers);

    for (int i = 0; i < numOfKeepers; ++i)
    {
        try
        {
            Keeper* keeper = new Keeper(keepersNames[i], keeperSalary, animals[i]);
            keepers->push_back(keeper);
        }
        catch (const string& errMessage)
        {
            cout << "Could not create keeper " << keepersNames[i] << endl << ":" << errMessage << endl << endl;
            (*keepers)[i] = nullptr;
            break;
        }
    }
    return *keepers;
}

void ZooManager::addKeepersToZoo(vector<Keeper*>& keepers, int numOfKeepers)
{
    int numOfAreas = theZoo->getNumOfAreas();
    vector<Area*>* areas = &theZoo->getAllAreas();

    for (int i = 0; i < numOfKeepers && i < numOfAreas; ++i)
    {
        try
        {
            theZoo->addWorker(*keepers[i], *((*areas)[i]));
        }
        catch (const string& errMessage)
        {
            cout << "Could not add keeper " << keepers[i]->getName() << " to the zoo:" << endl << errMessage << endl << endl;
        }
    }
}

vector<Veterinarian*>& ZooManager::createAllVeterinarian(int numOfVeterinarian)
{
    numOfVeterinarian = 3;
    const string vetsNames[] = { "Dr. Vivi", "Dr. Vuvu", "Dr. Kobi" };
    int vetsSalary = 10000, vetsLicenseNumbers[] = { 5, 8, 10 };

    vector<Veterinarian*>* vets = new vector<Veterinarian*>();
    vets->reserve(numOfVeterinarian);

    for (int i = 0; i < numOfVeterinarian; ++i)
    {
        try
        {
            Veterinarian* vet = new Veterinarian(vetsNames[i], vetsSalary, vetsLicenseNumbers[i]);
            vets->push_back(vet);
        }
        catch (const string& errMessage)
        {
            cout << "Could not create Veterinarian " << vetsNames[i] << ":" << endl << errMessage << endl << endl;
            (*vets)[i] = nullptr;
            break;
        }
    }
    return *vets;
}

void ZooManager::addAllVeterinarianToZoo(vector<Veterinarian*>& vets, int numOfVeterinarian)
{
    int numOfAreas = theZoo->getNumOfAreas();
    vector<Area*>* areas = &theZoo->getAllAreas();

    for (int i = 0; i < numOfVeterinarian && i < numOfAreas; i++)
    {
        try
        {
            theZoo->addWorker(*vets[i], *((*areas)[i]));
        }
        catch (const string& errMessage)
        {
            cout << "Could not add Veterinarian " << vets[i]->getName() << " to the zoo:" << endl << errMessage << endl << endl;
        }
    }
}