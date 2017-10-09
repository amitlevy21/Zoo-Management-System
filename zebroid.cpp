//
// Created by Moshe Sheena on 06/10/2017.
//

#include "zebroid.h"

Zebroid::Zebroid(const char *name, float weight, int birthYear, int numOfStripes, float sizeOfHorseShoe,
                 eAnimalClass animalClass)
        :Animal(name, weight, birthYear, animalClass), Horse(name, weight, birthYear, sizeOfHorseShoe, animalClass),
         Zebra(name, weight, birthYear, numOfStripes, animalClass)
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
//    os << ", horse shoe size: " <<  << ", number of stripes: "
//       << getNumOfStripes();
    Horse::toOs(os);
    Zebra::toOs(os);
}

