#include "zebra.h"

void Zebra::setNumOfStripes(int numOfStripes) throw(const string&)
{
    if(numOfStripes < 0)
        throw "Number of stripes cannot be a negative number";
}

Zebra::Zebra(const string& name, float weight, int birthYear, int numOfStripes, eAnimalClass animalClass)
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

const string& Zebra::getClassName() const
{
    return "Zebra";
}

