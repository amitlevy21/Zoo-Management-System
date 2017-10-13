//
// Created by Amit Levy on 07/10/17.
//

#include "keeper.h"
#include <string.h>

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
    os << "Keeper Details:"<<endl<<"Keeper Specialty: " << eAnimalString[keeperSpecialty] <<endl<< "Number of animals he's responsible of " << numOfAnimalsToTakeCare;
}

const string& Keeper::getWorkerType() const
{
    return "Keeper";
}

int Keeper::getNumOfAnimalsToTakeCare() const
{
    return numOfAnimalsToTakeCare;
}

void Keeper::notify(Animal &animalAdded)
{
    if(animalAdded.getClassName() == eAnimalString[keeperSpecialty])
    {
        numOfAnimalsToTakeCare++;
    }
}



