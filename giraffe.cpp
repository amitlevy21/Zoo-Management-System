//
// Created by Moshe Sheena on 06/10/2017.
//

#include "giraffe.h"

void Giraffe::setLengthOfNeck(float lengthOfNeck) throw(const char*)
{
    if(lengthOfNeck <= 0)
        throw "Giraffe neck length must be non negative non zero number";

    this->lengthOfNeck = lengthOfNeck;
}

Giraffe::Giraffe(const char *name, float weight, int birthYear, float lengthOfNeck, eAnimalClass animalClass)
        : Animal(name, weight, birthYear, animalClass)
//What about Area? why not received in c'tor?
{
    setLengthOfNeck(lengthOfNeck);
}

float Giraffe::getLengthOfNeck() const
{
    return lengthOfNeck;
}

void Giraffe::toOs(ostream &os) const
{
    os << ", length of neck: " << lengthOfNeck;
}

const char *Giraffe::getClassName() const
{
    return "Giraffe";
}

