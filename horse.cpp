//
// Created by Moshe Sheena on 06/10/2017.
//

#include "Horse.h"

void Horse::setSizeOfHorseShoe(float sizeOfHorseShoe)
{
    if(sizeOfHorseShoe <= 0)
        throw "Size of horse shoe must be a non negetive non zero number";

    this->sizeOfHorseShoe = sizeOfHorseShoe;
}

Horse::Horse(const char *name, float weight, int birthYear, float sizeOfHorseShoe)
        :Animal(name, weight, birthYear)
{
    setSizeOfHorseShoe(sizeOfHorseShoe);
}

int Horse::getSizeOfHorseShoe() const
{
    return sizeOfHorseShoe;
}

void Horse::toOs(ostream &os) const
{
    os << ", size of horse shoe: " << sizeOfHorseShoe;
}
