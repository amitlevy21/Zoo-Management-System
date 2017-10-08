//
// Created by Moshe Sheena on 06/10/2017.
//

#include "elephant.h"

void Elephant::setSizeOfEars(float sizeOfEars)
{
    if(sizeOfEars <= 0)
        throw "Ear size must be non negetive non zero number";

    this->sizeOfEars = sizeOfEars;
}

void Elephant::setLengthOfTrunk(float lengthOfTrunk)
{
    if(lengthOfTrunk <= 0)
        throw "Length of trunk must be a non negetive non zero number";

    this->lengthOfTrunk = lengthOfTrunk;
}

Elephant::Elephant(const char *name, float weight, int birthYear, float sizeOfEars, float lengthOfTrunk)
        :Animal(name, weight, birthYear)
{
    setSizeOfEars(sizeOfEars);
    setLengthOfTrunk(lengthOfTrunk);
}

float Elephant::getSizeOfEars() const
{
    return sizeOfEars;
}

float Elephant::getLengthOfTrunk() const
{
    return lengthOfTrunk;
}

void Elephant::toOs(ostream &os) const
{
    os << ", size of ears: " << sizeOfEars << ", length of trunk: " << lengthOfTrunk;
}



