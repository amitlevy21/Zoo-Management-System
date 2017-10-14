#include "areaManager.h"

AreaManager::AreaManager(const string& name, int salary, int yearsOfExperience, Area *area)
        : Worker(name, salary, area)
{
    setYearsOfExperience(yearsOfExperience);
}

void AreaManager::setYearsOfExperience(int yearsOfExperience) throw(const string&)
{
    if(yearsOfExperience < 0 )
    {
        throw "yearOfExperience cannot be negative";
    }
    this->yearsOfExperience = yearsOfExperience;
}

int AreaManager::getYearsOfExperience() const
{
    return yearsOfExperience;
}

void AreaManager::toOs(ostream &os) const
{
    os << "years of Experience: " << yearsOfExperience;
}

const string& AreaManager::getWorkerType() const
{
    return "AreaManager";
}


