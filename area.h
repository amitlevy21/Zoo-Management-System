//
//  Area.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __AREA_H
#define __AREA_H

#include <iostream>
#include "animal.h"
#include "observerInterface.h"
#include "myLinkedList.h"
#include <vector>

class Worker;
class AreaManager;

using namespace std;

class Area
{
private:
	string name;
    int numOfAnimals = 0;
    int maxNumberOfAnimals;
    int numOfWorkers = 0;
    int maxNumberOfWorkers;
	AreaManager* areaManager;
	MyLinkedList<Animal*> animals;
	vector<Worker*> workers;
	Animal::eAnimalClass habitat;

	const int MAX_NUM_OF_OBSERVERS = 15;
	Observer** observers = new Observer*[MAX_NUM_OF_OBSERVERS];
	int numOfObservers = 0;

	void setMaxNumberOfAnimals(int maxNumberOfAnimals) throw (const string&);
	void setMaxNumberOfWorkers(int maxNumberOfWorkers) throw (const string&);
    
public:
	Area(const string& name, int maxNumberOfAnimals, int maxNumberOfWorkers, Animal::eAnimalClass habitat, AreaManager* areaManager = nullptr);
    ~Area();
    
    Area(const Area& area) = delete;
    const Area& operator=(const Area& area) = delete;
    
     const string& getName() const;
    
     int getNumOfAnimals() const;
     int getMaxNumberOfAnimals() const;

	int getNumOfSpacesLeftInAreaForAnimals() const;

	 Animal::eAnimalClass getHabitat() 	const;
 
     int getNumOfWorkers() const;
     int getMaxNumberOfWorkers() const;
    
     const AreaManager& getAreaManager() const;
    void setAreaManager(AreaManager& areaManager);

	void setAreaName(const string& name);
    
	void addAnimal(Animal& animal) throw (const string&);
    
	void addWorker(Worker& worker) throw (const string&);
    
    const MyLinkedList<Animal*>& getAllAnimals() const;
    const vector<Worker*> getAllWorkers() const;
    
    const Area& operator+=(Animal& animal);

    bool operator<(const Area& other) const;
    
    bool operator>(const Area& other) const;
    
    bool operator==(const Area& other) const;
    
    friend ostream& operator<<(ostream& os, const Area& area);

    void registerObserver(Observer* obs);

	virtual void notifyAllObservers(Animal &animalAdded);
};


#endif /* __AREA_H */
