//
// Created by Moshe Sheena on 06/10/2017.
//

#include "../Animal.h"

void Animal::setWeight(float weight)
{
    if(weight <= 0)
        throw "weight must be a non negetive non zero number";

    this->weight = weight;
}

void Animal::setName(const char *name)
{
    if(strcmp(name, "") == 0)
        throw "name cannot be an empty string";

    this->name = strdup(name);
}

void Animal::setBirthYear(int birthYear)
{
    if(birthYear <= 0 || (birthYear > 0 && birthYear <= 1800))
        throw "animal birth year must be non negetive number or from 19th century";
}

Animal::Animal(const char *name, float weight, int birthYear, const Area *area)
{
    setName(name);
    setWeight(weight);
    setBirthYear(birthYear);

//Appears as question
//    if(area)
//        this->area = const_cast<Area*>(area);
}

void Animal::~Animal()
{
    delete[] name;
}

const char* Animal::getName() const
{
    return name;
}

int Animal::getBirthYear() const
{
    return birthYear;
}

float Animal::getWeight() const
{
    return weight;
}

ostream &operator<<(ostream &os, const Animal &animal)
{
    os << "Name: " << animal.name << ", weight: " << animal.weight << ", YOB: "
       << animal.birthYear << ", area: " << animal.area->getName();

    animal.toOs(os);

    return os;
}





