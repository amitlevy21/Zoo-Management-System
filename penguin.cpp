//
// Created by Moshe Sheena on 06/10/2017.
//

#include "Penguin.h"

Penguin::Penguin(const char *name, float weight, int birthYear, eSeaFood favoriteFood)
        :Animal(name, weight, birthYear)
{
    setFavoriteFood(favoriteFood);
}

eSeaFood Penguin::getFavoriteFood() const
{
    return favoriteFood;
}

void Penguin::setFavoriteFood(eSeaFood favoriteFood)
{
    if(this->favoriteFood == favoriteFood)
        return;

    this->favoriteFood = favoriteFood;
}

void Penguin::toOs(ostream &os) const
{
    os << ", favorite food: " << seaFood[favoriteFood];
}

