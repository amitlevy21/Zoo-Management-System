//
// Created by Moshe Sheena on 06/10/2017.
//

#include "penguin.h"

Penguin::Penguin(const char *name, float weight, int birthYear, eSeaFood favoriteFood, eAnimalClass animalClass)
        :Animal(name, weight, birthYear, animalClass)
{
    setFavoriteFood(favoriteFood);
}

Penguin::eSeaFood Penguin::getFavoriteFood() const
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

