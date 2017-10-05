//
//  main.cpp
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//
#pragma warning( disable : 4290 )
#include <iostream>
#include "Zoo.h"
#include "Area.h"
#include "Animal.h"
#include "Worker.h"
#include "AreaManager.h"
#include "Veterinarian.h"
#include "Keeper.h"
#include "MaintenanceWorker.h"
#include "Elephant.h"
#include "Giraffe.h"
#include "Horse.h"
#include "Lion.h"
#include "Penguin.h"
#include "Zebra.h"
#include "Zebroid.h"

using namespace std;

AreaManager** createAreaManagers(int& numOfManagers) throw(const char*);
Area** createAllAreas(AreaManager **managers, int& numOfAreas) throw(const char*);
void addAreasToZoo(Zoo& zoo, Area** areas, int& numOfAreas) throw(const char*);
Animal** createAnimals(int& numOfAnimals) throw(const char*);
void addAllAnimalsToZoo(Zoo& myZoo, Animal** animals, int &numOfAnimals) throw(const char*);
Keeper** createAllKeepers(int& numOfKeepers) throw(const char*);
void addKeepersToZoo(Zoo& myZoo, Keeper** keepers, int numOfKeepers) throw(const char*);
Veterinarian** createAllVeterinarian(int& numOfVeterinarian) throw(const char*);
void addAllVeterinarianToZoo(Zoo& myZoo, Veterinarian**vets, int numOfVeterinarian) throw(const char*);
void freeAllAreaManagers(AreaManager** areaManagers, int& numOfAreaManagers);
void freeAllAreas(Area** areas, int& numOfAreas);
void freeAllAnimals(Animal** animals, int& numOfAnimals);
void freeAllVeterinarian(Veterinarian** vets, int& numOfVeterinarian);
void freeAllKeepers(Keeper** keepers, int& numOfKeepers);

int main(int argc, const char * argv[]) 
{
	int numOfManagers, numOfAreas, numOfAnimals, numOfKeepers, numOfVeterinarian;
	AreaManager** managers = nullptr;
	Area** areas = nullptr;
	Animal** animals = nullptr;
	Keeper** keepers = nullptr;
	Veterinarian** vets = nullptr;

	try
	{
		Area quarentineArea("quarentineArea", 4, 4);
		Zoo myZoo("My Zoo", 10, quarentineArea);

		managers = createAreaManagers(numOfManagers);
	
		areas = createAllAreas(managers, numOfAreas);

		// add all areas
		addAreasToZoo(myZoo, areas, numOfAreas);

		animals = createAnimals(numOfAnimals);

		// add animals
		addAllAnimalsToZoo(myZoo, animals, numOfAnimals);

		keepers = createAllKeepers(numOfKeepers);

		// add all the keepers
		addKeepersToZoo(myZoo, keepers, numOfKeepers);

		vets = createAllVeterinarian(numOfVeterinarian);

		// add all vets
		addAllVeterinarianToZoo(myZoo, vets, numOfVeterinarian);
		
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

AreaManager** createAreaManagers(int& numOfManagers) throw(const char*)
{
	numOfManagers = 3;
	AreaManager** managers = new AreaManager*[numOfManagers];

	managers[0] = new AreaManager("Yogev", 31235, 5000, 123);
	managers[1] = new AreaManager("Moshe", 51455, 4500, 456);
	managers[2] = new AreaManager("Roie", 84578, 4800, 789);

	return managers;
}

Area** createAllAreas(AreaManager **managers, int& numOfAreas) throw(const char*)
{
	numOfAreas = 3;
	Area** areas = new Area*[numOfAreas];

	areas[0] = new Area("A1", 4, 4, managers[0]);
	areas[1] = new Area("A2", 4, 4, managers[1]);
	areas[2] = new Area("A3", 4, 4, managers[2]);
				
	return areas;
}

void addAreasToZoo(Zoo& zoo, Area** areas, int& numOfAreas) throw(const char*)
{
	for (int i = 0; i < numOfAreas; i++)
	{
		zoo.addArea(*areas[i]);
	}
}

Animal** createAnimals(int& numOfAnimals) throw(const char*)
{
	numOfAnimals = 4;
	Animal** animals = new Animal*[numOfAnimals];
	
	animals[0] = new Penguin("Pini", 1.2f, 2005, Penguin::eSeaFood::CRAB);
	animals[1] = new Elephant("Eli", 2.5f, 2003, 1.35f, 2.75f);
	animals[2] = new Horse("Horsy", 208.5f, 1998, 40.2f);
	animals[3] = new Zebroid("Zeze", 1.45f, 2010, 128, 38.6f);
						
	return animals;
}

void addAllAnimalsToZoo(Zoo& myZoo, Animal** animals, int &numOfAnimals) throw(const char*)
{
	for (int i = 0; i < numOfAnimals - 1; i++)
	{
		myZoo.addAnimal(*animals[i], myZoo.getAllAreas()[i]->getName());
	}

	// another animal to the last area
	myZoo.addAnimal(*animals[3], myZoo.getAllAreas()[2]->getName());
}

Keeper** createAllKeepers(int& numOfKeepers) throw(const char*)
{
	numOfKeepers = 3;
	Keeper** keepers = new Keeper*[numOfKeepers];

	keepers[0] = new Keeper("Kipi", 312542, 7500, Keeper::eAnimal::PENGUIN);
	keepers[1] = new Keeper("Keepi", 387542, 7500, Keeper::eAnimal::ELEPHANT);
	keepers[2] = new Keeper("Keepee", 955642, 7500, Keeper::eAnimal::HORSE);
	
	return keepers;
}

void addKeepersToZoo(Zoo& myZoo, Keeper** keepers, int numOfKeepers) throw(const char*)
{
	for (int i = 0; i < numOfKeepers; i++)
	{
		myZoo.addWorker(*keepers[i], myZoo.getAllAreas()[i]->getName());
	}
}

Veterinarian** createAllVeterinarian(int& numOfVeterinarian) throw(const char*)
{
	numOfVeterinarian = 3;
	Veterinarian** vets = new Veterinarian*[numOfVeterinarian];
	
	vets[0] = new Veterinarian("Vivi", 45875, 10000, 5);
	vets[1] = new Veterinarian("Vuvu", 87457, 10000, 8);
	vets[2] = new Veterinarian("Kobi", 26584, 10000, 10);
	
	return vets;
}

void addAllVeterinarianToZoo(Zoo& myZoo, Veterinarian**vets, int numOfVeterinarian) throw(const char*)
{
	for (int i = 0; i < numOfVeterinarian; i++)
	{
		myZoo.addWorker(*vets[i], myZoo.getAllAreas()[i]->getName());
	}
}

void freeAllAreaManagers(AreaManager** areaManagers, int& numOfAreaManagers)
{
	for (int i = 0; i < numOfAreaManagers; i++)
	{
		delete areaManagers[i];
	}

	delete []areaManagers;
}

void freeAllAreas(Area** areas, int& numOfAreas)
{
	for (int i = 0; i < numOfAreas; i++)
	{	
		delete areas[i];	
	}

	delete []areas;
}

void freeAllAnimals(Animal** animals, int& numOfAnimals)
{
	for (int i = 0; i < numOfAnimals; i++)
	{
		delete animals[i];
	}

	delete []animals;
}

void freeAllVeterinarian(Veterinarian** vets, int& numOfVeterinarian)
{
	for (int i = 0; i < numOfVeterinarian; i++)
	{
		delete vets[i];
	}

	delete []vets;
}

void freeAllKeepers(Keeper** keepers, int& numOfKeepers)
{
	for (int i = 0; i < numOfKeepers; i++)
	{
		delete keepers[i];
	}

	delete []keepers;
}