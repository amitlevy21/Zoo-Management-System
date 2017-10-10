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
using namespace std;

Area** createAllAreas(int numOfAreas) 						                    throw(const char*);
AreaManager** createAreaManagers(Zoo& myZoo, int numOfManagers)                 throw(const char*);
Keeper** createAllKeepers(Zoo& myZoo, int numOfKeepers)                         throw(const char*);
Veterinarian** createAllVeterinarian(Zoo& myZoo, int numOfVeterinarian)         throw(const char*);
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

    int maxNumOfWorkers = 0;
    int numOfManagers = 0;
    int numOfAreas = 0;
    int numOfAnimals = 0;
    int numOfKeepers = 0;
    int numOfVeterinarian = 0;
    int quarantineMaxNumOfWorkers = 0;
    int quarantineMaxNumOfAnimals = 0;

    int quarantineAnimalClassification = 0;

	try
	{
        
        cout << "Welcome to Zoo Management System!" << endl << endl;
        cout << "Enter Zoo Name: ";
        
        cin.getline(zooName,STRING_INPUT_LENGTH);
        
        cout << endl << "Enter max number of workers: ";
        
        cin >> maxNumOfWorkers;

        
        cout << endl << endl << "The zoo must have a quarantine area, Let's create it first." << endl;

        cin.ignore(); //clean buffer

        cout << "Enter Quarantine Area Name: ";

        cin.getline(quarantineAreaName, STRING_INPUT_LENGTH);

        cout << endl << "Enter max number of workers and then max number of animals for the quarantine area: ";

        cin >> quarantineMaxNumOfWorkers >> quarantineMaxNumOfAnimals;

        cout << "Enter Animal Classification for the quarantine area:" << endl << "0 - Land" << endl << "1 - Marine" << endl << "2 - Amphibian" << endl;

        cin >> quarantineAnimalClassification;

        Area quarantineArea(quarantineAreaName, quarantineMaxNumOfWorkers, quarantineMaxNumOfAnimals, (Animal::eAnimalClass)quarantineAnimalClassification);
        
		Zoo myZoo(zooName, maxNumOfWorkers, quarantineArea);

        cout << "Let's create the areas of the zoo" << endl << "Enter number of areas: ";

        cin >> numOfAreas;

        areas = createAllAreas(numOfAreas);

        addAreasToZoo(myZoo, areas, numOfAreas);

        cout << endl << "Let's create the managers of the zoo" << endl << "Enter number of managers: ";

        cin >> numOfManagers;

		managers = createAreaManagers(myZoo, numOfManagers);

        cout << endl << "Let's create the keepers of the zoo" << endl << "Enter number of keepers: ";

        cin >> numOfKeepers;

        keepers = createAllKeepers(myZoo, numOfKeepers);

        cout << endl << "Let's create the veterinarians of the zoo" << endl << "Enter number of veterinarians: ";

        cin >> numOfVeterinarian;

        vets = createAllVeterinarian(myZoo, numOfVeterinarian);

        cout << endl << "Let's create the animals of the zoo" << endl << "Enter number of animals: ";

        cin >> numOfAnimals;

		animals = createAnimals(numOfAnimals);

        bool roomForAllAnimals;
        do
        {
            roomForAllAnimals = addAnimalsToZoo(myZoo, animals, numOfAnimals);
            if(!roomForAllAnimals)
            {
                cout << "enter num of animals to add to the zoo: ";
                cin >> numOfAnimals;
                cout << endl;
            }

        }while(!roomForAllAnimals);


		addKeepersToZoo(myZoo, keepers, numOfKeepers);

		addVeterinariansToZoo(myZoo, vets, numOfVeterinarian);
		
		// print the whole zoo
		cout << "My Zoo: \n" << myZoo << endl;
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


Area** createAllAreas(int numOfAreas) throw(const char*)
{
    const int NUM_OF_ANIMAL_CLASSIFICATIONS = 2;
    Area** areas = new Area*[numOfAreas];
    for (int i = 0; i < numOfAreas; i++) {
        char areaName[STRING_INPUT_LENGTH];
        int maxNumOfAnimals = 0;
        int maxNumOfWorkers = 0;
        int areaAnimalClassification = 0;

        cout << "Enter name for area #" << i << " :";
        cin >> areaName;
        do
        {
            cout << endl << "Enter max num of animals for " << areaName << ": ";
            cin >> maxNumOfAnimals;

        }while(!inputValidationNonNegative(maxNumOfAnimals));

        do
        {
            cout << endl << "Enter max num of workers for " << areaName << ": ";
            cin >> maxNumOfWorkers;

        }while(!inputValidationNonNegative(maxNumOfWorkers));

        do
        {
            cout << "Enter Animal Classification for " << areaName << ": " << endl << "0 - Land" << endl << "1 - Marine" << endl << "2 - Amphibian" << endl;

            cin >> areaAnimalClassification;

        }while(areaAnimalClassification < 0 || areaAnimalClassification > NUM_OF_ANIMAL_CLASSIFICATIONS);

        areas[i] = new Area(areaName,maxNumOfAnimals,maxNumOfWorkers,(Animal::eAnimalClass)areaAnimalClassification);

    }

    return areas;
}

AreaManager** createAreaManagers(Zoo& myZoo, int numOfManagers) throw(const char*)
{
	AreaManager** managers = new AreaManager *[numOfManagers];


    for (int i = 0; i < numOfManagers; i++) {
        char *managerName[STRING_INPUT_LENGTH];
        int salary = 0;
        int yearsOfExperience = 0;
        int assignToArea = 0;

        inputForWorker(i + 1, (char**)managerName, &salary, "manager");
        do
        {
            cout << endl << "Enter years of experience of " << managerName << ": ";
            cin >> yearsOfExperience;

        }while(!inputValidationNonNegative(yearsOfExperience));

        do
        {
            cout << endl << "If you wish you can assign " << managerName << " to an area by entering the area's index. " << endl <<
                 "Areas that already have manager will be overwritten" << endl <<
                    "Enter -1 if you don't want to assign him to any area right now: " << endl;
            cin >> assignToArea;
        }while(assignToArea != -1 || !inputValidationNonNegative(assignToArea));

        if(assignToArea == -1)
        {
            managers[i] = new AreaManager(*managerName, salary, yearsOfExperience);
        }
        else
        {
            Area* areaToAssign = (const_cast<Area*> (&myZoo[assignToArea]));
            managers[i] = new AreaManager(*managerName, salary, yearsOfExperience, areaToAssign);
        }

    }

	return managers;
}

Keeper** createAllKeepers(Zoo& myZoo, int numOfKeepers) throw(const char*)
{
    Keeper** keepers = new Keeper *[numOfKeepers];

    const int NUM_OF_ANIMAL_TYPES = 6;

    for (int i = 0; i < numOfKeepers; i++) {
        char* keeperName[STRING_INPUT_LENGTH];
        int salary = 0;
        int keeperSpeciality = 0;
        int assignToArea = 0;

        inputForWorker(i + 1 , (char**)keeperName, &salary, "keeper");
        do
        {
            cout << "Enter Keeper Speciality for " << keeperName << ": " << endl << "0 - Lion" << endl << "1 - Penguin" << endl << "2 - Elephant" << endl
                    << "3 - Giraffe" << endl << "4 - Zebra" << endl << "5 - Horse" << endl << "6 - Zebroid" << endl;

            cin >> keeperSpeciality;

        }while(keeperSpeciality < 0 || keeperSpeciality > NUM_OF_ANIMAL_TYPES);

        do
        {
            cout << endl << "If you wish you can assign " << keeperName << " to an area by entering the area's index. " << endl <<
                 "Enter -1 if you don't want to assign him to any area right now: " << endl;
            cin >> assignToArea;

        }while(assignToArea != -1 || !inputValidationNonNegative(assignToArea));

        if(assignToArea == -1)
        {
            Area* areaToAssign = (const_cast<Area*> (&myZoo[assignToArea]));
            keepers[i] = new Keeper(*keeperName,salary,(Keeper::eAnimalSpeciality)keeperSpeciality, areaToAssign);
        }
        else
        {
            keepers[i] = new Keeper(*keeperName,salary,(Keeper::eAnimalSpeciality)keeperSpeciality);
        }

    }

    return keepers;
}

Veterinarian** createAllVeterinarian(Zoo& myZoo, int numOfVeterinarian) throw(const char*)
{
    Veterinarian** vets = new Veterinarian*[numOfVeterinarian];

    for (int i = 0; i < numOfVeterinarian; i++) {
        char nameOfVeterinarian[STRING_INPUT_LENGTH];
        int salary = 0;
        int licenseNumber = 0;
        int assignToArea = 0;

        inputForWorker(i + 1, (char**)&nameOfVeterinarian, &salary, "veterinarian");
        do
        {
            cout << endl << "Enter license number for " << nameOfVeterinarian << ": ";
            cin >> licenseNumber;

        }while(!inputValidationNonNegative(licenseNumber));

        do
        {
            cout << endl << "If you wish you can assign " << nameOfVeterinarian << " to an area by entering the area's index. " << endl <<
                 "Enter -1 if you don't want to assign him to any area right now: " << endl;
            cin >> assignToArea;
        }while(assignToArea != -1 || !inputValidationNonNegative(assignToArea));

        if(assignToArea == -1)
        {
            vets[i] = new Veterinarian(nameOfVeterinarian, salary, licenseNumber);
        }
        else
        {
            Area* areaToAssign = (const_cast<Area*> (&myZoo[assignToArea]));
            vets[i] = new Veterinarian(nameOfVeterinarian, salary, licenseNumber, areaToAssign);
        }

    }

    return vets;
}

Animal** createAnimals(int numOfAnimals) throw(const char*)
{
    const int NUM_OF_ANIMAL_CLASSIFICATIONS = 2;

    Animal** animals = new Animal*[numOfAnimals];
/*
    for (int i = 0; i < numOfAnimals; i++) {
        char* animalName = nullptr;
        float weight = 0;
        int birthYear = 0;
        int animalClass = 0;

        cout << "Enter name for animal #" << i << ":";
        cin >> animalName;
        do
        {
            cout << endl << "Enter weight for " << animalName << ": ";
            cin >> weight;

        }while(!inputValidationNonNegative((int)weight));

        do
        {
            cout << endl << "Enter birth year for " << animalName << ": ";
            cin >> birthYear;

        }while(!inputValidationNonNegative(birthYear));

        do
        {
            cout << "Enter Animal Classification for " << animalName << ": " << endl << "0 - Land" << endl << "1 - Marine" << endl << "2 - Amphibian" << endl;

            cin >> animalClass;

        }while(animalClass < 0 || animalClass > NUM_OF_ANIMAL_CLASSIFICATIONS);

    }*/


    animals[0] = new Penguin("Pini", 1.2f, 2005, Penguin::eSeaFood::CRAB, Animal::eAnimalClass::AMPHIBIAN);
    animals[1] = new Elephant("Eli", 2.5f, 2003, 1.35f, 2.75f, Animal::eAnimalClass::LAND);
    animals[2] = new Horse("Horsy", 208.5f, 1998, 40.2f, Animal::eAnimalClass::LAND);
    animals[3] = new Zebroid("Zeze", 1.45f, 2010, 128, 38.6f, Animal::eAnimalClass::LAND);

    return animals;
}

void inputForWorker(int indexForPrinting, char** name, int* salary, const char* role)
{
    cout << "Enter name for " << role <<" #" << indexForPrinting << ": ";
    cin >> *name;
    do
    {
        cout << endl << "Enter salary for " << *name << ": ";
        cin >> *salary;

    }while(!inputValidationNonNegative(*salary));
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
	int areaChoice;

	cout << "new keepers that were hired by the zoo:" << endl;
	for (int i = 0; i < numOfKeepers; i++)
	{
		cout << i+1 << ") " << keepers[i]->getName() << endl;
	}

	for (int i = 0; i < numOfKeepers; i++)
	{
		cout << "in which area would you like to assign keeper #" << i+1 << " ?";
		cin >> areaChoice;
		zoo.addWorker(*keepers[i], *zoo.getAllAreas()[areaChoice]);
	}

}

void addVeterinariansToZoo(Zoo& zoo, Veterinarian** vets, int numOfVeterinarian) throw(const char*)
{
	int areaChoice;

	cout << "new veterinarians that were hired by the zoo:" << endl;
	for (int i = 0; i < numOfVeterinarian; i++)
	{
		cout << i+1 << ") " << vets[i]->getName() << endl;
	}

	for (int i = 0; i < numOfVeterinarian; i++)
	{
		cout << "in which area would you like to assign keeper #" << i+1 << " ?";
		cin >> areaChoice;
		zoo.addWorker(*vets[i], *zoo.getAllAreas()[areaChoice]);
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



