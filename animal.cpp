#include "animal.h"
#include "area.h"

void Animal::setName(const string& name) throw(const string&)
{
    if(name.empty())
        throw "animal name cannot be an empty string";

    this->name = name;
}

void Animal::setWeight(float weight)    throw(const string&)
{
    if(weight <= 0)
        throw "weight cannot be zero or negative";

    this->weight = weight;
}

void Animal::setBirthYear(int birthYear) throw(const string&)
{
    const int NINETEENTH_CENTURY = 1800;
    if(birthYear < NINETEENTH_CENTURY)
        throw "no animal is documented to live from before the nineteenth century.";

    this->birthYear = birthYear;
}

Animal::Animal(const string& name, float weight, int birthYear, eAnimalClass animalClass)
        :animalClass(animalClass)
{
    setWeight(weight);
    setBirthYear(birthYear);
    setName(name);
}

ostream &operator<<(ostream &os, const Animal &animal)
{
    os << "name: " << animal.name.c_str() << ", class: " << animalClasses[static_cast<int>(animal.getAnimalClass())] << ", weight: " << animal.weight << ", YOB: "
       << animal.birthYear << ", area: " << animal.area->getName().c_str();

    animal.toOs(os);

    return os;
}

bool Animal::operator==(const Animal& other)
{
    return this->name == other.name;

}

const string& Animal::getName() const
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

inline Animal::eAnimalClass Animal::getAnimalClass() const
{
    return animalClass;
}


