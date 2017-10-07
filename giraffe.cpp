//
// Created by Moshe Sheena on 06/10/2017.
//

#include "Giraffe.h"

void Giraffe::setLengthOfNeck(float lengthOfNeck)
{
    if(lengthOfNeck <= 0)
        throw "Giraffe neck length must be non negetive non zero number";

    this->lengthOfNeck = lengthOfNeck;
}

Giraffe::Giraffe(const char *name, float weight, int birthYear, float lengthOfNeck)
        : Animal(name, weight, birthYear)
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
