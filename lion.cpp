//
// Created by Moshe Sheena on 06/10/2017.
//

#include "lion.h"

Lion::Lion(const char *name, float weight, int birthYear, eManeColor maneColor)
        :Animal(name, weight, birthYear)
{
    this->maneColor = maneColor;
}

Lion::eManeColor Lion::getManeColor() const
{
    return maneColor;
}

void Lion::toOs(ostream &os) const
{
    os << ", color of mane: " << maneColors[maneColor];
}

