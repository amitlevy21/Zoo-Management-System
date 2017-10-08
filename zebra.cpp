//
// Created by Moshe Sheena on 06/10/2017.
//

#include "zebra.h"

void Zebra::setNumOfStripes(int numOfStripes)
{
    if(numOfStripes < 0)
        throw "Number of stripes cannot be a negetive number";
}

Zebra::Zebra(const char *name, float weight, int birthYear, int numOfStripes)
        :Animal(name, weight, birthYear)
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

