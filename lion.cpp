#include "lion.h"

Lion::Lion(const string& name, float weight, int birthYear, eManeColor maneColor, eAnimalClass animalClass)
        :Animal(name, weight, birthYear, animalClass)
{
    this->maneColor = maneColor;
}

Lion::eManeColor Lion::getManeColor() const
{
    return maneColor;
}

void Lion::toOs(ostream &os) const
{
    os << ", color of mane: " << maneColors[maneColor].c_str();
}

const string& Lion::getClassName() const {
    return "Lion";
}

