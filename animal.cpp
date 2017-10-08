//
// Created by Moshe Sheena on 07/10/2017.
//

#include "Animal.h"

void Animal::setName(const char *name)
{
    if(strcmp(name, "") == 0)
        throw "animal name cannot be an empty string";
    if(!name)
        throw "animal name cannot be null";

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

Animal::Animal(const char *name, float weight, int birthYear)
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

bool Animal::operator==(const Animal& other)
{
    if(strcmp(this->name, other.name) == 0)
        return true;

    return false;
}

const char *Animal::getName() const
{
    return name;
}

float Animal::getWeight() const
{
    return weight;
}

int Animal::getBirthYear() const
{
    return birthYear;
}

void Animal::setArea(Area& area)
{
    if(this->area != nullptr)
    {
        if(*this->area == area)
            return;
    }

    this->area = &area;
    area.addAnimal(*this);
}

