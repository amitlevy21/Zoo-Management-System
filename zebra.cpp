//
// Created by Moshe Sheena on 06/10/2017.
//

#include "zebra.h"

void Zebra::setNumOfStripes(int numOfStripes) throw(const char*)
{
    if(numOfStripes < 0)
        throw "Number of stripes cannot be a negetive number";
}

Zebra::Zebra(const char *name, float weight, int birthYear, int numOfStripes, eAnimalClass animalClass)
        :Animal(name, weight, birthYear, animalClass)
{
    setNumOfStripes(numOfStripes);
}

int Zebra::getNumOfStripes() const
{
    return numOfStripes;
}

void Zebra::toOs(ostream &os) const
{
    os << ", number of stripes: " << numOfStripes;
}

const char *Zebra::getClassName() const
{
    return "Zebra";
}

