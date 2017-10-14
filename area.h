#ifndef __AREA_H
#define __AREA_H

#include <iostream>
#include "animal.h"
#include "observerInterface.h"
#include "myLinkedList.h"
#include <vector>

using namespace std;

class Worker;
class AreaManager;

class Area
{
private:
	string name;
    int maxNumberOfAnimals;
    int maxNumberOfWorkers;
	AreaManager* areaManager;
	MyLinkedList<Animal*> animals;
	vector<Worker*> workers;
	Animal::eAnimalClass habitat;

	const int INITIAL_OBSERVER_NUM = 15;
	vector<Observer*> observers;

	void setMaxNumberOfAnimals(int maxNumberOfAnimals) throw (const string&);
	void setMaxNumberOfWorkers(int maxNumberOfWorkers) throw (const string&);
    
public:
	Area(const string& name, int maxNumberOfAnimals, int maxNumberOfWorkers, Animal::eAnimalClass habitat, AreaManager* areaManager = nullptr);
    ~Area();
    
    Area(const Area& area) = delete;
    const Area& operator=(const Area& area) = delete;
    
    const string& getName()                    const;
    
    inline int getNumOfAnimals()               const;
    inline int getMaxNumberOfAnimals()         const;

    Animal::eAnimalClass getHabitat() 	       const;
 
    int getNumOfWorkers()                      const;
    int getMaxNumberOfWorkers()                const;
    
    const AreaManager& getAreaManager()        const;
    void setAreaManager(AreaManager& areaManager);

	void setAreaName(const string& name);
    
	void addAnimal(Animal& animal) throw (const string&);
                                                        //both parameters aren't const because they call setArea()
	void addWorker(Worker& worker) throw (const string&);
    
    const MyLinkedList<Animal*>& getAllAnimals()    const;
    const vector<Worker*>&       getAllWorkers()    const;
    
    const Area& operator+=(Animal& animal);

    bool operator<(const Area& other) const;
    
    bool operator>(const Area& other) const;
    
    bool operator==(const Area& other)const;
    
    friend ostream& operator<<(ostream& os, const Area& area);

    void registerObserver(Observer& obs);

	virtual void notifyAllObservers(const Animal& animalAdded);
};


#endif /* __AREA_H */
