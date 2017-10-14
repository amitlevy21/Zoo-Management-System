#include "penguin.h"

Penguin::Penguin(const string& name, float weight, int birthYear, eSeaFood favoriteFood, eAnimalClass animalClass)
        :Animal(name, weight, birthYear, animalClass), favoriteFood(favoriteFood)
{}

Penguin::eSeaFood Penguin::getFavoriteFood() const
{
    return favoriteFood;
}

void Penguin::toOs(ostream &os) const
{
    os << ", favorite food: " << seaFood[favoriteFood].c_str();
}

const string& Penguin::getClassName() const
{
    return "Penguin";
}

