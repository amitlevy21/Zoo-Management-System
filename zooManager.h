//
// Created by Amit Levy on 11/10/17.
//

#ifndef ZOO_MANAGEMENT_SYSTEM_ZOOMANAGER_H
#define ZOO_MANAGEMENT_SYSTEM_ZOOMANAGER_H


#include "zoo.h"
#include "keeper.h"
#include "veterinarian.h"


//facade class
class ZooManager
{
private:
    Zoo* theZoo;


public:
    ZooManager(Zoo& myZoo);

    AreaManager** createAreaManagers(int numOfManagers);

    Keeper** createAllKeepers(int numOfKeepers);

    Veterinarian** createAllVeterinarian(int numOfVeterinarian);

    Area** createAllAreas(int numOfAreas, AreaManager** managers, int numOfManagers);

    Animal** createAnimals(int numOfAnimals);

    void addAreasToZoo(Area** areas, int numOfAreas);

    void addAllAnimalsToZoo(Animal** animals, int numOfAnimals);

    void addKeepersToZoo(Keeper** keepers, int numOfKeepers);

    void addAllVeterinarianToZoo(Veterinarian**vets, int numOfVeterinarian);



};


#endif //ZOO_MANAGEMENT_SYSTEM_ZOOMANAGER_H
