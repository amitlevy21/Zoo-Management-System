//
// Created by Amit Levy on 11/10/17.
//

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

AreaManager** ZooManager::createAreaManagers(int numOfManagers)
{
    numOfManagers = 3;
    const char* managersNames[] = { "Yogev", "Moshe", "Roie" };
    int managersSalary[] = { 5000, 4500, 4800 };
    int managersYearsOfExperience[] = { 2, 3, 4 };

    AreaManager** managers = new AreaManager*[numOfManagers];

    for (int i = 0; i < numOfManagers; i++)
    {
        try
        {
            managers[i] = new AreaManager(managersNames[i], managersSalary[i], managersYearsOfExperience[i]);
        }
        catch (const char* errMessage)
        {
            cout << "Could not create manager " << managersNames[i] << ":" << endl << errMessage << endl << endl;
            managers[i] = nullptr;
            numOfManagers = i;
            break;
        }
    }

    return managers;
}

Area** ZooManager::createAllAreas(int numOfAreas, AreaManager** managers, int numOfManagers)
{
    numOfAreas = 3;
    int maxNumberOfAnimals = 4, maxNumberOfWorkers = 4, wrongMaxNumberOfAnimals = -5;
    const char* areasNames[] = { "A1", "A2", "A3" };
    Animal::eAnimalClass classes[] = {Animal::eAnimalClass::LAND, Animal::eAnimalClass::MARINE, Animal::eAnimalClass::AMPHIBIAN};
    Area** areas = new Area*[numOfAreas];

    for (int i = 0; i < numOfAreas; i++)
    {
        try
        {
            areas[i] = new Area(areasNames[i], maxNumberOfAnimals, maxNumberOfWorkers, classes[i], managers[i]);
        }
        catch (const char* errMessage)
        {
            cout << "Could not create area " << areasNames[i] << ":" << endl << errMessage << endl << endl;
            areas[i] = nullptr;
            numOfAreas = i;
            break;
        }
    }

    return areas;
}

void ZooManager::addAreasToZoo(Area** areas, int numOfAreas)
{
    for (int i = 0; i < numOfAreas; i++)
    {
        try
        {
            theZoo->addArea(*areas[i]);
        }
        catch (const char* errMessage)
        {
            cout << "Area " << areas[i]->getName() << " was not added to the zoo:" << endl << errMessage << endl << endl;
        }
    }
}

Animal** ZooManager::createAnimals(int numOfAnimals)
{
    numOfAnimals = 4;
    const char* names[] = { "Horsy", "Pini", "Eli", "Zeze" };
    Animal** animals = new Animal*[numOfAnimals];

    for (int i = 0; i < numOfAnimals; i++)
    {
        try
        {
            switch (i%numOfAnimals)
            {
                case 0:
                {
                    animals[i] = new Horse(names[i], 208.5f, 1998, 40.2f, Animal::eAnimalClass::LAND);
                    break;
                }
                case 1:
                {
                    animals[i] = new Penguin(names[i], 1.2f, 2005, Penguin::CRAB, Animal::eAnimalClass::AMPHIBIAN);
                    break;
                }
                case 2:
                {
                    animals[i] = new Elephant(names[i], 2.5f, 2000, 1.35f, 2.75f, Animal::eAnimalClass::LAND);
                    break;
                }
                case 3:
                {
                    animals[i] = new Zebroid(names[i], 1.45f, 2010, 128, 38.6f, Animal::eAnimalClass::LAND);
                    break;
                }
            }
        }
        catch (const char *errMessage)
        {
            cout << "Could not create animal " << names[i] << ":" << endl << errMessage << endl << endl;
            animals[i] = nullptr;
            numOfAnimals = i;
            break;
        }
    }
    return animals;
}

void ZooManager::addAllAnimalsToZoo(Animal** animals, int numOfAnimals)
{
    int numOfAreas = theZoo->getNumOfAreas();
    Area** areas = theZoo->getAllAreas();
    for (int i = 0; i < numOfAnimals && i < numOfAreas; i++)
    {
        try
        {
            theZoo->addAnimal(*animals[i], *areas[i]);
        }
        catch (const char* errMessage)
        {
            cout << "Could not add " << animals[i]->getName() << ":" << endl << errMessage << endl << endl;
        }
    }

    // another animal to the last area
    theZoo->addAnimal(*animals[3], *areas[2]);
}

Keeper** ZooManager::createAllKeepers(int numOfKeepers)
{
    numOfKeepers = 3;
    const char*  keepersNames[] = { "Kipi", "Keepi", "Keepee" };
    int keeperSalary = 7500;
    Keeper::eAnimalSpeciality animals[] = { Keeper::HORSE, Keeper::ELEPHANT, Keeper::HORSE };
    Keeper** keepers = new Keeper*[numOfKeepers];

    for (int i = 0; i < numOfKeepers; i++)
    {
        try
        {
            keepers[i] = new Keeper(keepersNames[i], keeperSalary, animals[i]);
        }
        catch (const char* errMessage)
        {
            cout << "Could not create keeper " << keepers[i]->getName() << endl << ":" << errMessage << endl << endl;
            keepers[i] = nullptr;
            numOfKeepers = i;
            break;
        }
    }

    return keepers;
}

void ZooManager::addKeepersToZoo(Keeper** keepers, int numOfKeepers)
{
    int numOfAreas = theZoo->getNumOfAreas();
    Area** areas = theZoo->getAllAreas();

    for (int i = 0; i < numOfKeepers && i < numOfAreas; i++)
    {
        try
        {
            theZoo->addWorker(*keepers[i], *areas[i]);
        }
        catch (const char* errMessage)
        {
            cout << "Could not add keeper " << keepers[i]->getName() << " to the zoo:" << endl << errMessage << endl << endl;
        }
    }
}

Veterinarian** ZooManager::createAllVeterinarian(int numOfVeterinarian)
{
    numOfVeterinarian = 3;
    const char* vetsNames[] = { "Dr. Vivi", "Dr. Vuvu", "Dr. Kobi" };
    int vetsSalary = 10000, vetsLicenseNumbers[] = { 5, 8, 10 };
    Veterinarian** vets = new Veterinarian*[numOfVeterinarian];

    for (int i = 0; i < numOfVeterinarian; i++)
    {
        try
        {
            vets[i] = new Veterinarian(vetsNames[i], vetsSalary, vetsLicenseNumbers[i]);
        }
        catch (const char* errMessage)
        {
            cout << "Could not create Veterinarian " << vets[i]->getName() << ":" << endl << errMessage << endl << endl;
            vets[i] = nullptr;
            numOfVeterinarian = i;
            break;
        }
    }

    return vets;
}

void ZooManager::addAllVeterinarianToZoo(Veterinarian**vets, int numOfVeterinarian)
{
    int numOfAreas = theZoo->getNumOfAreas();
    Area** areas = theZoo->getAllAreas();

    for (int i = 0; i < numOfVeterinarian && i < numOfAreas; i++)
    {
        try
        {
            theZoo->addWorker(*vets[i], *areas[i]);
        }
        catch (const char* errMessage)
        {
            cout << "Could not add Veterinarian " << vets[i]->getName() << " to the zoo:" << endl << errMessage << endl << endl;
        }
    }
}