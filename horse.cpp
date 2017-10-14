//
// Created by Moshe Sheena on 06/10/2017.
//

#include "horse.h"

void Horse::setSizeOfHorseShoe(float sizeOfHorseShoe) throw(const string&)
{
    if(sizeOfHorseShoe <= 0)
        throw "Size of horse shoe must be a non negative non zero number";

    this->sizeOfHorseShoe = sizeOfHorseShoe;
}

Horse::Horse(const string& name, float weight, int birthYear, float sizeOfHorseShoe, eAnimalClass animalClass)
        :Animal(name, weight, birthYear, animalClass)
{
    setSizeOfHorseShoe(sizeOfHorseShoe);
}

float Horse::getSizeOfHorseShoe() const
{
    return sizeOfHorseShoe;
}

void Horse::toOs(ostream &os) const
{
    os << ", size of horse shoe: " << sizeOfHorseShoe;
}

const string& Horse::getClassName() const
{
    return "Horse";
}

