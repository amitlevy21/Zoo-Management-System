//
// Created by Moshe Sheena on 07/10/2017.
//

#include "Animal.h"

void Animal::setName(const char *name)
{
    if(strcmp(name, "") == 0)
        throw "animal name cannot be an empty string";

    this->name = strdup(name);
}

void Animal::setWeight(float weight)
{
    if(weight <= 0)
        throw "weight cannot be zero or negetive";

    this->weight = weight;
}

void Animal::setBirthYear(int birthYear)
{
    const int NINETEENTH_CENTURY = 1800;
    if(birthYear < NINETEENTH_CENTURY)
        throw "no animal is documented to live from before the nineteenth century.";

    this->birthYear = birthYear;
}

Animal::Animal(const char *name, float weight, int birthYear, const Area *area)
{
    setWeight(weight);
    setBirthYear(birthYear);
    setName(name);
}

ostream &operator<<(ostream &os, const Animal &animal)
{
    os << "Name: " << animal.name << ", weight: " << animal.weight << ", YOB: "
       << animal.birthYear << ", area: " << animal.area->getName();

    animal.toOs(os);

    return os;
}

void Animal::~Animal()
{
    delete[] name;
}

void Animal::setArea(const Area *area)
{
    if(!area)
        throw "area non existent";

    if(this->area != area)
        this->area = area;
}

