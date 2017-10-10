//
// Created by Amit Levy on 07/10/17.
//

#include "keeper.h"

Keeper::Keeper(const char *name, long idNumber, int salary, eAnimal keeperSpecialty, Area *area) :
        Worker(name, salary, area), keeperSpecialty(keeperSpecialty)
{
}

Keeper::eAnimal Keeper::getKeeperSpecialty() const
{
    return keeperSpecialty;
}

void Keeper::toOs(ostream &os) const
{
    os << "Keeper Details:\nKeeper Specialty: " << eAnimalString[keeperSpecialty];
}


