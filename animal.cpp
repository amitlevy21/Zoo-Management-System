//
// Created by Moshe Sheena on 07/10/2017.
//

#include "animal.h"
#include "area.h"

#include <string.h>


void Animal::setName(const char *name) throw(const char*)
{
    if(strcmp(name, "") == 0)
        throw "animal name cannot be an empty string";
    if(!name)
        throw "animal name cannot be null";

    this->name = strdup(name);
}

void Animal::setWeight(float weight) throw(const char*)
{
    if(weight <= 0)
        throw "weight cannot be zero or negative";

    this->weight = weight;
}

void Animal::setBirthYear(int birthYear) throw(const char*)
{
    const int NINETEENTH_CENTURY = 1800;
    if(birthYear < NINETEENTH_CENTURY)
        throw "no animal is documented to live from before the nineteenth century.";

    this->birthYear = birthYear;
}

Animal::Animal(const char *name, float weight, int birthYear, eAnimalClass animalClass)
        :animalClass(animalClass)
{
    setWeight(weight);
    setBirthYear(birthYear);
    setName(name);
}

ostream &operator<<(ostream &os, const Animal &animal)
{
    os << "Name: " << animal.name << ", class: " << animalClasses[static_cast<int>(animal.getAnimalClass())] << ", weight: " << animal.weight << ", YOB: "
       << animal.birthYear << ", area: " << animal.area->getName();

    animal.toOs(os);

    return os;
}

Animal::~Animal()
{
    delete[] name;
}

bool Animal::operator==(const Animal& other)
{
    return strcmp(this->name, other.name) == 0;

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

eAnimalClass Animal::getAnimalClass() const
{
    return animalClass;
}


