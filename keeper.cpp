//
// Created by Amit Levy on 07/10/17.
//

#include "keeper.h"
#include <string.h>

Keeper::Keeper(const char *name, int salary, eAnimalSpeciality keeperSpecialty, Area *area) :
        Worker(name, salary, area), keeperSpecialty(keeperSpecialty)
{
}

Keeper::eAnimalSpeciality Keeper::getKeeperSpecialty() const
{
    return keeperSpecialty;
}

void Keeper::toOs(ostream &os) const
{
    os << "Keeper Details:\nKeeper Specialty: " << eAnimalString[keeperSpecialty];
}

const char *Keeper::getWorkerType() const
{
    return "Keeper";
}

int Keeper::getNumOfAnimalsToTakeCare() const
{
    return numOfAnimalsToTakeCare;
}

void Keeper::notify(Animal &animalAdded)
{
    if(strcmp(animalAdded.getClassName(), eAnimalString[keeperSpecialty]) == 0)
    {
        numOfAnimalsToTakeCare++;
    }
}



