//
// Created by Amit Levy on 11/10/17.
//

#include "zooManager.h"
#include "elephant.h"
#include "giraffe.h"
#include "horse.h"
#include "lion.h"
#include "penguin.h"
#include "zebroid.h"
#include "areaManager.h"

const int STRING_INPUT_LENGTH = 15;


ZooManager::ZooManager(Zoo &myZoo)
{
    theZoo = &myZoo;
}

Worker **ZooManager::createAllWorkers(int numOfWorkers)
{
    Worker** workers = new Worker*[numOfWorkers];

    for (int i = 0; i < numOfWorkers; i++) {
        char *workerName = new char[STRING_INPUT_LENGTH];
        int salary = 0;
        int assignToArea = 0;
        int workerType = 0;

        cout << "Which type of worker would you like to create?" << endl << "0 - Area Manager" << endl << "1 - Keeper"
             << endl << "2 - Maintenance worker" << endl << "3 - Veterinarian" << endl;

        cin >> workerType;

        cout << endl;

        inputForWorker(i + 1, &workerName, &salary, &assignToArea);

        switch(workerType)
        {
            case 0:
            {
                workers[i] = createAreaManager(workerName,salary,assignToArea);
                break;
            }

            case 1:
            {
                workers[i] = createKeeper(workerName,salary,assignToArea);
                break;
            }

            case 2:
            {
                workers[i] = createMaintenanceWorker(workerName, salary, assignToArea);
                break;
            }

            case 3:
            {
                workers[i] = createVeterinarian(workerName, salary, assignToArea);
                break;
            }

            default:
            {
                cout << "Invalid choice! please try again" << endl;
                i--; //prevent gaps in the array, reenter values for the same worker
                break;
            }
        }
    }
    return workers;
}

AreaManager *ZooManager::createAreaManager(const char *managerName, int salary, int assignToArea) const throw(const char*)
{
    AreaManager* areaManager = nullptr;
    int yearsOfExperience = 0;

    do
    {
        cout << endl << "Enter years of experience of " << managerName << ": ";
        cin >> yearsOfExperience;

    }while(!inputValidationNonNegative(yearsOfExperience));

    if(assignToArea == -1)
    {
        areaManager = new AreaManager(managerName, salary, yearsOfExperience);
    }
    else
    {
        Area* areaToAssign = ((*theZoo).getAllAreas()[assignToArea]);
        areaManager = new AreaManager(managerName, salary, yearsOfExperience, areaToAssign);
    }
    return areaManager;
}

Keeper *ZooManager::createKeeper(const char *keeperName, int salary, int assignToArea) const throw(const char*)
{
    Keeper* keeper = nullptr;

    const int NUM_OF_ANIMAL_TYPES = 7;


    int keeperSpeciality = 0;

    do
    {
        cout << endl << "Enter Keeper Speciality for " << keeperName << ": " << endl << "0 - Lion" << endl << "1 - Penguin" << endl << "2 - Elephant" << endl
             << "3 - Giraffe" << endl << "4 - Zebra" << endl << "5 - Horse" << endl << "6 - Zebroid" << endl;

        cin >> keeperSpeciality;

    }while(keeperSpeciality < 0 || keeperSpeciality >= NUM_OF_ANIMAL_TYPES);

    cout << endl;

    if(assignToArea == -1)
    {
        keeper = new Keeper(keeperName,salary,(Keeper::eAnimalSpeciality)keeperSpeciality);
    }
    else
    {
        Area* areaToAssign = (*theZoo).getAllAreas()[assignToArea];
        keeper = new Keeper(keeperName,salary,(Keeper::eAnimalSpeciality)keeperSpeciality, areaToAssign);
    }

    return keeper;
}

MaintenanceWorker *
ZooManager::createMaintenanceWorker(const char *maintenanceWorkerName, int salary, int assignToArea) const throw(const char*)
{
    MaintenanceWorker* maintenanceWorker = nullptr;

    float shoeSize = 0;

    do
    {
        cout << endl << "Enter shoe size for " << maintenanceWorkerName << ": ";
        cin >> shoeSize;

    }while(!inputValidationNonNegative((int)shoeSize));

    cout << endl;

    if(assignToArea == -1)
    {
        maintenanceWorker = new MaintenanceWorker(maintenanceWorkerName, salary, shoeSize);
    }
    else
    {
        Area* areaToAssign = (*theZoo).getAllAreas()[assignToArea];
        maintenanceWorker = new MaintenanceWorker(maintenanceWorkerName, salary, shoeSize, areaToAssign);
    }

    return maintenanceWorker;
}

Veterinarian *
ZooManager::createVeterinarian(const char *veterinarianName, int salary, int assignToArea) const throw(const char*)
{
    Veterinarian* veterinarian = nullptr;

    int licenseNumber = 0;

    do
    {
        cout << endl << "Enter license number for " << veterinarianName << ": ";
        cin >> licenseNumber;

    }while(!inputValidationNonNegative(licenseNumber));

    if(assignToArea == -1)
    {
        veterinarian = new Veterinarian(veterinarianName, salary, licenseNumber);
    }
    else
    {
        Area* areaToAssign = (*theZoo).getAllAreas()[assignToArea];
        veterinarian = new Veterinarian(veterinarianName, salary, licenseNumber, areaToAssign);
    }

    return veterinarian;
}

Area **ZooManager::createAllAreas(int numOfAreas) const throw(const char*)
{
    const int NUM_OF_ANIMAL_CLASSIFICATIONS = 2;
    Area** areas = new Area*[numOfAreas];
    for (int i = 0; i < numOfAreas; i++)
    {
        char* areaName = new char[STRING_INPUT_LENGTH];
        int maxNumOfAnimals = 0;
        int maxNumOfWorkers = 0;
        int areaAnimalClassification = 0;

        cout << "Enter name for area #" << i+1 << ": ";
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

        cout << endl;
        do
        {
            cout << "Enter Animal Classification for " << areaName << ": " << endl << "0 - Land" << endl << "1 - Marine" << endl << "2 - Amphibian" << endl;

            cin >> areaAnimalClassification;

        }while(areaAnimalClassification < 0 || areaAnimalClassification > NUM_OF_ANIMAL_CLASSIFICATIONS);

        cout << endl;

        areas[i] = new Area(areaName,maxNumOfAnimals,maxNumOfWorkers,(Animal::eAnimalClass)areaAnimalClassification);

    }

    return areas;
}

Animal **ZooManager::createAnimals(int numOfAnimals) const throw(const char*)
{
    const int RANGE_OF_ANIMAL_TYPES = 6;

    Animal** animals = new Animal*[numOfAnimals];

    for (int i = 0; i < numOfAnimals; i++)
    {
        char* animalName = new char[STRING_INPUT_LENGTH];
        int animalChoice = 0;
        float weight = 0;
        int birthYear = 0;

        do
        {
            cout << endl << "This zoo can currently house any one of these fine creatures:" << endl;
            cout << "0 - Elephant" << endl << "1 - Giraffe" << endl << "2 - Horse" << endl << "3 - Lion" << endl << "4 - Penguin" << endl
                 << "5 - Zebra" << endl << "6 - Zebroid" << endl;

            cin >> animalChoice;

        }while(animalChoice < 0 || animalChoice > RANGE_OF_ANIMAL_TYPES);

        cin.ignore(); //clear buffer

        cout << endl << "Enter name for animal #" << (i + 1) << ":";
        cin.getline(animalName, STRING_INPUT_LENGTH);
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

        switch (animalChoice)
        {
            case 0:
            {
                float sizeOfEars = 0;
                float lengthOfTrunk = 0;

                do
                {
                    cout << endl << "Enter size of ears for " << animalName<< ": ";
                    cin >> sizeOfEars;

                }while(!inputValidationNonNegative((int)sizeOfEars));

                do
                {
                    cout << endl <<  "Enter length of trunk for " << animalName << ": ";
                    cin >> lengthOfTrunk;

                }while(!inputValidationNonNegative((int)lengthOfTrunk));

                animals[i] = new Elephant(animalName, weight, birthYear, sizeOfEars, lengthOfTrunk, Animal::eAnimalClass::LAND);
                break;

            }

            case 1:
            {
                int lengthOfNeck = 0;

                do
                {
                    cout << endl << "Enter Giraffe length of neck for " << animalName << ": ";
                    cin >> lengthOfNeck;

                }while(!inputValidationNonNegative(lengthOfNeck));

                animals[i] = new Giraffe(animalName, weight, birthYear,lengthOfNeck,Animal::eAnimalClass::LAND);
                break;
            }

            case 2:
            {
                float sizeOfHorseShoe = 0;

                do
                {
                    cout << endl << "Enter size of horse shoe for " << animalName << ": ";
                    cin >> sizeOfHorseShoe;

                }while(!inputValidationNonNegative((int)sizeOfHorseShoe));
                animals[i] = new Horse(animalName, weight, birthYear, sizeOfHorseShoe, Animal::eAnimalClass::LAND);
                break;
            }

            case 3:
            {
                int maneColor = 0;
                const int NUM_OF_MANE_COLORS = 5;

                do
                {
                    cout << endl << "Enter mane color for " << animalName << endl
                         << "0 - White" << endl << "1 - Brown" << endl << "2 - Yellow" << endl << "3 - Red" << endl << "4 - Orange" << endl;
                    cin >> maneColor;

                }while(maneColor < 0 || maneColor >= NUM_OF_MANE_COLORS);

                animals[i] = new Lion(animalName, weight, birthYear, (Lion::eManeColor )maneColor, Animal::eAnimalClass::LAND);
                break;
            }

            case 4:
            {
                int favouriteSeaFood = 0;
                const int NUM_OF_SEA_FOOD_TYPES = 4;

                do
                {
                    cout << "Enter favourite sea food for " << animalName << endl
                         << "0 - Shrimp" << endl << "1 - Crab" << endl << "2 - Fish" << endl << "3 - Calamari" << endl;
                    cin >> favouriteSeaFood;

                }while(favouriteSeaFood < 0 || favouriteSeaFood >= NUM_OF_SEA_FOOD_TYPES);

                animals[i] = new Penguin(animalName, weight, birthYear, (Penguin::eSeaFood) favouriteSeaFood, Animal::eAnimalClass::AMPHIBIAN);
                break;
            }

            case 5:
            {
                int numOfStripes = 0;

                do
                {
                    cout << endl << "Enter num of stripes for " << animalName << ": ";
                    cin >> numOfStripes;

                }while(!inputValidationNonNegative(numOfStripes));

                animals[i] = new Giraffe(animalName, weight, birthYear,numOfStripes,Animal::eAnimalClass::LAND);
                break;
            }

            case 6:
            {
                int numOfStripes = 0;
                float sizeOfHorseShoe = 0;

                do
                {
                    cout << endl << "Enter num of stripes for " << animalName << ": ";
                    cin >> numOfStripes;

                }while(!inputValidationNonNegative(numOfStripes));

                do
                {
                    cout << endl <<  "Enter size of horse shoe for " << animalName << ": ";
                    cin >> sizeOfHorseShoe;

                }while(!inputValidationNonNegative((int)sizeOfHorseShoe));

                animals[i] = new Zebroid(animalName, weight, birthYear , numOfStripes ,sizeOfHorseShoe, Animal::eAnimalClass::LAND);
                break;
            }

            default:
            {
                cout << "Invalid input! please try again" << endl;
                i--;
                break;
            }
        }

    }

    return animals;
}

void ZooManager::addAreasToZoo(Area **areas, int numOfAreas) const throw(const char*)
{
    for (int i = 0; i < numOfAreas; i++)
    {
        (*theZoo).addArea(*areas[i]);
    }
}

void ZooManager::addWorkersToZoo(Worker **workers, int numOfWorkers) const throw(const char*)
{
    int areaChoice;
    for (int i = 0; i < numOfWorkers; i++)
    {
        cout << "in which area would you like to assign worker #" << i + 1 << "of type " << workers[i]->getWorkerType() << "?";
        cin >> areaChoice;
        (*theZoo).addWorker(*workers[i], *(*theZoo).getAllAreas()[areaChoice]);

    }
}

bool ZooManager::addAnimalsToZoo(Animal **animals, int numOfAnimals) const
{
    int numOfSpacesAvailableInZoo = 0;

    for (int j = 0; j < (*theZoo).getNumOfAreas(); j++)
    {
        numOfSpacesAvailableInZoo += (*theZoo).getAllAreas()[j]->getNumOfSpacesLeftInAreaForAnimals();
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
        areaIndex = findAreaByHabitat((const Area**)(*theZoo).getAllAreas(), (*theZoo).getNumOfAreas(), animals[i]->getAnimalClass());
        if(areaIndex == -1)
        {
            cout << "failed to find area for animal in index " << i;
            return false;
        }
        (*theZoo).getAllAreas()[areaIndex]->addAnimal(*animals[i]);
    }
    return true;
}

void ZooManager::inputForWorker(int indexForPrinting, char** name, int* salary,int* assignToArea) const
{
    cout << "Enter name for worker #" << indexForPrinting << ": ";
    cin >> *name;
    do
    {
        cout << endl << "Enter salary for " << *name << ": ";
        cin >> *salary;

    }while(!inputValidationNonNegative(*salary));

    do
    {
        cout << endl << "If you wish to assign " << *name << " to an area by entering the area's index. " << endl <<
             "Enter -1 if you don't want to assign him to any area right now: " << endl;
        cin >> *assignToArea;
    }while(*assignToArea != -1 && !inputValidationNonNegative(*assignToArea));
}

bool ZooManager::inputValidationNonNegative(int inputFromUser) const
{
    if (inputFromUser < 0)
    {
        cout << "Invalid input! please try again with a value greater than zero" << endl;
        return false;
    }

    return true;
}

int ZooManager::findAreaByHabitat(const Area *const *const areas, int numOfAreas, Animal::eAnimalClass habitat) const {
    for (int i = 0; i < numOfAreas; i++)
    {
        if(areas[i]->getHabitat() == habitat || areas[i]->getHabitat() == Animal::eAnimalClass::AMPHIBIAN)
            return i;
    }

    return -1;
}

void ZooManager::freeAllAreas(Area **areas, int numOfAreas) const
{
    for (int i = 0; i < numOfAreas; i++)
    {
        delete areas[i];
    }

    delete []areas;
}

void ZooManager::freeAllWorkers(Worker **workers, int numOfWorkers) const
{
    for (int i = 0; i < numOfWorkers; i++)
    {
        delete workers[i];
    }

    delete []workers;
}

void ZooManager::freeAllAnimals(Animal **animals, int numOfAnimals) const
{
    for (int i = 0; i < numOfAnimals; i++)
    {
        delete animals[i];
    }

    delete []animals;
}

