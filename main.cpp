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
#include "zooManager.h"

using namespace std;

const int STRING_INPUT_LENGTH = 15;


int main(int argc, const char * argv[])
{
	
	Area** areas = nullptr;
	Animal** animals = nullptr;
	Worker** workers = nullptr;

    ZooManager* zooManager = nullptr;
    
    char zooName[STRING_INPUT_LENGTH];
    char quarantineAreaName[STRING_INPUT_LENGTH];

    int maxNumOfWorkers = 0;
    int numOfWorkers = 0;
    int numOfAreas = 0;
    int numOfAnimals = 0;
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
        
		Zoo* myZoo =  Zoo::getInstance(zooName, maxNumOfWorkers, quarantineArea);

        zooManager = new ZooManager(*myZoo);

        cout << endl << endl;

        cout << "Let's create the areas of the zoo" << endl << "Enter number of areas: ";

        cin >> numOfAreas;

        cout << endl;

        areas = zooManager->createAllAreas(numOfAreas);

        zooManager->addAreasToZoo(areas, numOfAreas);

        cout << endl << "Let's create the workers of the zoo" << endl << "Enter number of workers: ";

        cin >> numOfWorkers;

        cout << endl;

		workers = zooManager->createAllWorkers(numOfWorkers);

        cout << endl << endl << "Let's create the animals of the zoo" << endl << "Enter number of animals: ";

        cin >> numOfAnimals;

		animals = zooManager->createAnimals(numOfAnimals);

        bool roomForAllAnimals;
        do
        {
            roomForAllAnimals = zooManager->addAnimalsToZoo(animals, numOfAnimals);
            if(!roomForAllAnimals)
            {
                cout << endl << "enter num of animals to add to the zoo: ";
                cin >> numOfAnimals;
                cout << endl;
            }

        }while(!roomForAllAnimals);


		zooManager->addWorkersToZoo(workers, numOfWorkers);
		
		// print the whole zoo
		cout << "My Zoo: \n" << *myZoo << endl;
	}
	catch (const char* e)
	{
		cout << e;
	}
	catch (...)
	{
		cout << "Something went wrong..";
	}

    if(zooManager)
    {
        // free all allocations
        zooManager->freeAllAnimals(animals, numOfAnimals);
        zooManager->freeAllAreas(areas, numOfAreas);
        zooManager->freeAllWorkers(workers, numOfWorkers);
    }

    return 0;
}





