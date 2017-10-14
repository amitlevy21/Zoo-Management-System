#include "keeper.h"

Keeper::Keeper(const string& name, int salary, eAnimalSpeciality keeperSpecialty, Area *area) :
        Worker(name, salary, area), keeperSpecialty(keeperSpecialty)
{
}

Keeper::eAnimalSpeciality Keeper::getKeeperSpecialty() const
{
    return keeperSpecialty;
}

void Keeper::toOs(ostream &os) const
{
    os <<", keeper Specialty: " << eAnimalString[keeperSpecialty] << ", number of animals he's responsible of: " << numOfAnimalsToTakeCare;
}

const string& Keeper::getWorkerType() const
{
    return "Keeper";
}

int Keeper::getNumOfAnimalsToTakeCare() const
{
    return numOfAnimalsToTakeCare;
}

void Keeper::notify(const Animal &animalAdded)
{
    if(animalAdded.getClassName() == eAnimalString[keeperSpecialty])
    {
        numOfAnimalsToTakeCare++;
    }
}



