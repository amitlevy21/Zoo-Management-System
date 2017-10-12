//
//  main.cpp
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//
#pragma warning( disable : 4290 )
#include <iostream>
#include "zoo.h"
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
#include "myLinkedList.h"
using namespace std;

Area **createAllAreas(int numOfAreas, AreaManager **managers)                                            throw(const char*);
AreaManager **createAreaManagers(int numOfManagers)                 throw(const char*);
Keeper **createAllKeepers(int numOfKeepers)                         throw(const char*);
Veterinarian **createAllVeterinarian(int numOfVeterinarian)         throw(const char*);
Animal** createAnimals(int numOfAnimals) throw(const char*);


void addAreasToZoo(Zoo& zoo, Area** areas, int numOfAreas) 						throw(const char*);
bool addAnimalsToZoo(Zoo &zoo, Animal **animals, int numOfAnimals);
void addKeepersToZoo(Zoo &zoo, Keeper **keepers, int numOfKeepers) 				throw(const char*);
void addVeterinariansToZoo(Zoo &zoo, Veterinarian **vets, int numOfVeterinarian)throw(const char*);

void inputForWorker(int indexForPrinting, char** name,int* salary, const char* role);

void freeAllAreaManagers(AreaManager** areaManagers, int numOfAreaManagers);
void freeAllAreas(Area** areas, int numOfAreas);
void freeAllAnimals(Animal** animals, int numOfAnimals);
void freeAllVeterinarian(Veterinarian** vets, int numOfVeterinarian);
void freeAllKeepers(Keeper** keepers, int numOfKeepers);

int findAreaByHabitat(const Area *const *const areas, int numOfAreas, Animal::eAnimalClass habitat);
bool inputValidationNonNegative(int inputFromUser);

const int STRING_INPUT_LENGTH = 15;

int main(int argc, const char * argv[])
{

	AreaManager** managers = nullptr;
	Area** areas = nullptr;
	Animal** animals = nullptr;
	Keeper** keepers = nullptr;
	Veterinarian** vets = nullptr;
    
    char zooName[STRING_INPUT_LENGTH];
    char quarantineAreaName[STRING_INPUT_LENGTH];

    int maxNumOfWorkers = 30;
    int numOfManagers = 3;
    int numOfAreas = 3;
    int numOfAnimals = 7;
    int numOfKeepers = 3;
    int numOfVeterinarian = 3;
//    int quarantineMaxNumOfWorkers = 5;
//    int quarantineMaxNumOfAnimals = 5;
//
//    int quarantineAnimalClassification = 0;

	try
	{
        cout << "Welcome to Zoo Management System!" << endl << endl;
        cout << "Enter Zoo Name: ";
        
        cin.getline(zooName,STRING_INPUT_LENGTH);

        Area quarantineArea("quarentineArea", 4, 4, Animal::eAnimalClass::AMPHIBIAN);
        
		Zoo myZoo(zooName, maxNumOfWorkers, quarantineArea);

        managers = createAreaManagers(numOfManagers);

        areas = createAllAreas(numOfAreas, managers);

        addAreasToZoo(myZoo, areas, numOfAreas);

        keepers = createAllKeepers(numOfKeepers);

        addKeepersToZoo(myZoo, keepers, numOfKeepers);

        vets = createAllVeterinarian(numOfVeterinarian);

        addVeterinariansToZoo(myZoo, vets, numOfVeterinarian);

		animals = createAnimals(numOfAnimals);

        addAnimalsToZoo(myZoo, animals, numOfAnimals);

		// print the whole zoo
		cout << "My Zoo:" << endl << myZoo << endl;
	}
	catch (const char* e)
	{
		cout << e;
	}
	catch (...)
	{
		cout << "Something went wrong..";
	}

	// free all allocations
	freeAllAnimals(animals, numOfAnimals);
	freeAllAreaManagers(managers, numOfManagers);
	freeAllAreas(areas, numOfAreas);
	freeAllKeepers(keepers, numOfKeepers);
	freeAllVeterinarian(vets, numOfVeterinarian);

    return 0;
}


Area **createAllAreas(int numOfAreas, AreaManager** managers) throw(const char*)
{
    numOfAreas = 3;

    Area** areas = new Area*[numOfAreas];

    areas[0] = new Area("Land walkers", 5, 5, Animal::eAnimalClass::LAND, managers[0]);
    areas[1] = new Area("Marine life", 5, 5, Animal::eAnimalClass::MARINE, managers[1]);
    areas[2] = new Area("Creepy crawlers", 5, 5, Animal::eAnimalClass::AMPHIBIAN, managers[2]);

    return areas;
}

AreaManager** createAreaManagers(int numOfManagers) throw(const char*)
{
    numOfManagers = 3;
    const char* areaMangerNames[] = {"Itay", "Moshe", "Amit"};
    int salaries[]= {31235, 51455, 84578};
    int yearsOfExperience[] = {5, 4, 7};

    AreaManager** managers = new AreaManager*[numOfManagers];

    for (int i = 0; i < numOfManagers; ++i)
    {
        try
        {
            managers[i] = new AreaManager(areaMangerNames[i], salaries[i], yearsOfExperience[i]);
        }catch (const char* msg)
        {
            cout << msg << endl;
            cout << i << " area managers were created. cannot continue creation." << endl;
            for (int j = i; j < numOfManagers; ++j)
            {
                delete managers[j];
            }
            numOfManagers = i;
        }
    }
    return managers;
}

Keeper** createAllKeepers(int numOfKeepers) throw(const char*)
{
    numOfKeepers = 3;

    Keeper** keepers = new Keeper*[numOfKeepers];

    keepers[0] = new Keeper("Haim", 312542, Keeper::eAnimalSpeciality::PENGUIN);
    keepers[1] = new Keeper("Mosh", 387542, Keeper::eAnimalSpeciality::ELEPHANT);
    keepers[2] = new Keeper("Ezra", 955642, Keeper::eAnimalSpeciality::HORSE);

    return keepers;
}

Veterinarian **createAllVeterinarian(int numOfVeterinarian) throw(const char*)
{
    numOfVeterinarian = 3;

    Veterinarian** vets = new Veterinarian*[numOfVeterinarian];

    vets[0] = new Veterinarian("Vivi", 45875, 10303);
    vets[1] = new Veterinarian("Vuvu", 87457, 24537);
    vets[2] = new Veterinarian("Kobi", 26584, 67849);

    return vets;
}

Animal** createAnimals(int numOfAnimals) throw(const char*)
{
    numOfAnimals = 7;

    Animal** animals = new Animal*[numOfAnimals];

	animals[0] = new Lion("Arie", 35.5f, 2003, Lion::eManeColor::BROWN, Animal::eAnimalClass::LAND);
	animals[1] = new Penguin("Noot", 45.6f, 2007, Penguin::eSeaFood::CRAB, Animal::eAnimalClass::MARINE);
	animals[2] = new Horse("Seabiscuit", 98.4f, 1992, 16.5f, Animal::eAnimalClass::LAND);
	animals[3] = new Zebra("Marti", 46.8f, 1996, 4, Animal::eAnimalClass::AMPHIBIAN);
    animals[4] = new Elephant("Dumbo", 445.6f, 2008, 67.8f, 12.1f, Animal::eAnimalClass::LAND);
    animals[5] = new Giraffe("Melman", 120.5f, 1997, 15.7f, Animal::eAnimalClass::LAND);
    animals[6] = new Zebroid("Prometheous", 90.2f, 2015, 18, 34.6f, Animal::eAnimalClass::AMPHIBIAN);

    return animals;
}

void addAreasToZoo(Zoo& zoo, Area** areas, int numOfAreas) throw(const char*)
{
	for (int i = 0; i < numOfAreas; i++)
	{
		zoo.addArea(*areas[i]);
	}
}


bool addAnimalsToZoo(Zoo &zoo, Animal **animals, int numOfAnimals)
{
    int numOfSpacesAvailableInZoo = 0;

    for (int j = 0; j < zoo.getNumOfAreas(); j++)
    {
        numOfSpacesAvailableInZoo += zoo.getAllAreas()[j]->getNumOfSpacesLeftInAreaForAnimals();
    }

    if(numOfSpacesAvailableInZoo < numOfAnimals)
    {
        cout << "no room for all animals. try again with " << numOfAnimals - numOfSpacesAvailableInZoo
             << " animals";
        return false;
    }

	int areaIndex;

	for (int i = 0; i < numOfAnimals; i++)
	{
		areaIndex = findAreaByHabitat((const Area**)zoo.getAllAreas(), zoo.getNumOfAreas(), animals[i]->getAnimalClass());
		if(areaIndex == -1)
        {
            cout << "failed to find area for animal in index " << i;
            return false;
        }
        zoo.getAllAreas()[areaIndex]->addAnimal(*animals[i]);
	}
	return true;
}

int findAreaByHabitat(const Area *const*const areas, int numOfAreas, Animal::eAnimalClass habitat)
{
    for (int i = 0; i < numOfAreas; i++)
	{
		if(areas[i]->getHabitat() == habitat)
			return i;
	}

    return -1;
}


void addKeepersToZoo(Zoo &zoo, Keeper **keepers, int numOfKeepers) throw(const char*)
{
    for (int i = 0; i < numOfKeepers; i++)
	{
        zoo.addWorker(*keepers[i], *zoo.getAllAreas()[i]);
	}

}

void addVeterinariansToZoo(Zoo& zoo, Veterinarian** vets, int numOfVeterinarian) throw(const char*)
{
    for (int i = 0; i < numOfVeterinarian; i++)
	{
		zoo.addWorker(*vets[i], *zoo.getAllAreas()[i]);
	}
}

void freeAllAreaManagers(AreaManager** areaManagers, int numOfAreaManagers)
{
	for (int i = 0; i < numOfAreaManagers; i++)
	{
		delete areaManagers[i];
	}

	delete []areaManagers;
}

void freeAllAreas(Area** areas, int numOfAreas)
{
	for (int i = 0; i < numOfAreas; i++)
	{	
		delete areas[i];	
	}

	delete []areas;
}

void freeAllAnimals(Animal** animals, int numOfAnimals)
{
	for (int i = 0; i < numOfAnimals; i++)
	{
		delete animals[i];
	}

	delete []animals;
}

void freeAllVeterinarian(Veterinarian** vets, int numOfVeterinarian)
{
	for (int i = 0; i < numOfVeterinarian; i++)
	{
		delete vets[i];
	}

	delete []vets;
}

void freeAllKeepers(Keeper** keepers, int numOfKeepers)
{
	for (int i = 0; i < numOfKeepers; i++)
	{
		delete keepers[i];
	}

	delete []keepers;
}


/** Returns false and prints error message if inputFromUser is a negative number, true otherwise*/
bool inputValidationNonNegative(int inputFromUser)
{
    if (inputFromUser < 0)
    {
        cout << "Invalid input! please try again with a value greater than zero" << endl;
        return false;
    }

    return true;
}



