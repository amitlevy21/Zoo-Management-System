//
// Created by Moshe Sheena on 06/10/2017.
//

#include "zebroid.h"

Zebroid::Zebroid(const char *name, float weight, int birthYear, int numOfStripes, float sizeOfHorseShoe)
        :Animal(name, weight, birthYear), Horse(name, weight, birthYear, sizeOfHorseShoe),
         Zebra(name, weight, birthYear, numOfStripes)
{
}

const char* Zebroid::getName() const
{
    return Animal::getName();
}

float Zebroid::getWeight() const
{
    return Animal::getWeight();
}

int Zebroid::getBirthYear() const
{
    return Animal::getBirthYear();
}

void Zebroid::toOs(ostream &os) const
{
    os << ", horse shoe size: " << Horse::getSizeOfHorseShoe() << ", number of stripes: "
       << Zebra::getNumOfStripes();
}

