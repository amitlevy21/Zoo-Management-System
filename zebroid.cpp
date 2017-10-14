#include "zebroid.h"

Zebroid::Zebroid(const string& name, float weight, int birthYear, int numOfStripes, float sizeOfHorseShoe,
                 eAnimalClass animalClass)
        :Animal(name, weight, birthYear, animalClass), Horse(name, weight, birthYear, sizeOfHorseShoe, animalClass),
         Zebra(name, weight, birthYear, numOfStripes, animalClass)
{
}

const string& Zebroid::getName() const
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
    Horse::toOs(os);
    os << endl;
    Zebra::toOs(os);
}

const string& Zebroid::getClassName() const
{
    return "Zebroid";
}

