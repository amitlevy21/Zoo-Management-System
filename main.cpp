#pragma warning( disable : 4290 )

#include <iostream>
using namespace std;
#include "zoo.h"
#include "zooManager.h"
#include "areaManager.h"


int main()
{
    try
    {
        AreaManager quarantineManager("Meny", 5468, 50000);
        Area quarantineArea("quarantineArea", 4, 4, Animal::eAnimalClass::LAND, &quarantineManager);

        Zoo* myZoo = Zoo::getInstance("My Zoo", 10, quarantineArea);

        ZooManager zooManager(*myZoo);

        int numOfManagers = 3;
        AreaManager** managers = zooManager.createAreaManagers(numOfManagers);

        int numOfAreas = 3;
        Area** areas = zooManager.createAllAreas(numOfAreas, managers, numOfManagers);

        // add all areas
        zooManager.addAreasToZoo(areas, numOfAreas);

        int numOfKeepers = 3;
        Keeper** keepers = zooManager.createAllKeepers(numOfKeepers);

        // add all the keepers
        zooManager.addKeepersToZoo(keepers, numOfKeepers);

        int numOfAnimals = 4;

        Animal** animals = zooManager.createAnimals(numOfAnimals);

        // add animals
        zooManager.addAllAnimalsToZoo(animals, numOfAnimals);


        int numOfVeterinarian = 3;
        Veterinarian** vets = zooManager.createAllVeterinarian(numOfVeterinarian);

        // add all vets
        zooManager.addAllVeterinarianToZoo(vets, numOfVeterinarian);

        // print the whole zoo
        cout << "My Zoo: \n" << *myZoo << endl << endl;

    }
    catch (const char* message)
    {
        cout << message;
    }
    catch (...)
    {
        cout << "Something went wrong" << endl;
    }

    return 0;
}
