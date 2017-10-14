#ifndef ZOO_MANAGEMENT_SYSTEM_ZOOMANAGER_H
#define ZOO_MANAGEMENT_SYSTEM_ZOOMANAGER_H

#include "zoo.h"
#include "keeper.h"
#include "veterinarian.h"
#include <vector>

class ZooManager
{
private:
    Zoo* theZoo;

public:
    ZooManager(Zoo& myZoo);

    vector<AreaManager*>& createAreaManagers(int numOfManagers);

    vector<Keeper*>& createAllKeepers(int numOfKeepers);

    vector<Veterinarian*>& createAllVeterinarian(int numOfVeterinarian);

    vector<Area*>& createAllAreas(int numOfAreas, vector<AreaManager*>& managers);

    vector<Animal*>& createAnimals(int numOfAnimals);

    void addAreasToZoo(vector<Area*>& areas, int numOfAreas);

    void addAllAnimalsToZoo(vector<Animal*>& animals, int numOfAnimals);

    void addKeepersToZoo(vector<Keeper*>& keepers, int numOfKeepers);

    void addAllVeterinarianToZoo(vector<Veterinarian*>& vets, int numOfVeterinarian);

};

#endif //ZOO_MANAGEMENT_SYSTEM_ZOOMANAGER_H
