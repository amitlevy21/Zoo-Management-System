//
// Created by Amit Levy on 11/10/17.
//

#ifndef ZOO_MANAGEMENT_SYSTEM_ZOOMANAGER_H
#define ZOO_MANAGEMENT_SYSTEM_ZOOMANAGER_H


#include "zoo.h"
#include "maintenanceWorker.h"
#include "veterinarian.h"
#include "keeper.h"

//facade class
class ZooManager
{
private:
    Zoo* theZoo;
    void inputForWorker(int indexForPrinting, char** name, int* salary,int* assignToArea) const;
    bool inputValidationNonNegative(int inputFromUser) const;
    int findAreaByHabitat(const Area *const *const areas, int numOfAreas, Animal::eAnimalClass habitat) const;


public:
    ZooManager(Zoo& myZoo);

    Worker** createAllWorkers(int numOfWorkers);

    AreaManager* createAreaManager(const char* managerName, int salary, int assignToArea) const throw(const char*);

    Keeper* createKeeper(const char*keeperName, int salary, int assignToArea) const throw(const char*);

    MaintenanceWorker* createMaintenanceWorker(const char* maintenanceWorkerName, int salary, int assignToArea) const throw(const char*);

    Veterinarian* createVeterinarian(const char *veterinarianName, int salary, int assignToArea) const throw(const char*);

    Area** createAllAreas(int numOfAreas) const throw(const char*);

    Animal** createAnimals(int numOfAnimals) const throw(const char*);

    void addAreasToZoo(Area** areas, int numOfAreas) const throw(const char*);

    void addWorkersToZoo(Worker** workers, int numOfWorkers) const throw(const char*);

    bool addAnimalsToZoo(Animal **animals, int numOfAnimals) const;

    void freeAllAreas(Area** areas, int numOfAreas)const;
    void freeAllWorkers(Worker** workers, int numOfWorkers)const;
    void freeAllAnimals(Animal** animals, int numOfAnimals)const;

};


#endif //ZOO_MANAGEMENT_SYSTEM_ZOOMANAGER_H
