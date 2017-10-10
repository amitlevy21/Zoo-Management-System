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

//class Animal;
class Worker;
class AreaManager;

//#include "AnimalClassify.h"
#include "animal.h"

using namespace std;

class Area
{
private:
    char *name;
    int numOfAnimals = 0;
    int maxNumberOfAnimals;
    int numOfWorkers = 0;
    int maxNumberOfWorkers;
	AreaManager* areaManager;
	Animal** animals;
	Worker** workers;
	Animal::eAnimalClass habitat;

	void setMaxNumberOfAnimals(int maxNumberOfAnimals) throw (const char*);
	void setMaxNumberOfWorkers(int maxNumberOfWorkers) throw (const char*);
    
public:
	Area(const char *name, int maxNumberOfAnimals, int maxNumberOfWorkers, Animal::eAnimalClass habitat, AreaManager* areaManager = nullptr);
    ~Area();
    
    Area(const Area& area) = delete;
    const Area& operator=(const Area& area) = delete;
    
     const char* getName() const;
    
     int getNumOfAnimals() const;
     int getMaxNumberOfAnimals() const;

	int getNumOfSpacesLeftInAreaForAnimals() const;

	 Animal::eAnimalClass getHabitat() 	const;
 
     long getNumOfWorkers() const;
     long getMaxNumberOfWorkers() const;
    
     const AreaManager& getAreaManager() const;
    void setAreaManager(AreaManager& areaManager);

	void setAreaName(const char* name);
    
	void addAnimal(Animal& animal) throw (const char*);
    
	void addWorker(Worker& worker) throw (const char*);
    
    const Animal** getAllAnimals() const;
    const Worker** getAllworkers() const;
    
    const Area& operator+=(Animal& animal);

    bool operator<(const Area& other) const;
    
    bool operator>(const Area& other) const;
    
    bool operator==(const Area& other) const;
    
    friend ostream& operator<<(ostream& os, const Area& area);
    
};


#endif /* __AREA_H */
