//
// Created by Amit Levy on 07/10/17.
//

#include "areaManager.h"

AreaManager::AreaManager(const char *name, int salary, int yearsOfExperience, Area *area) : Worker(name, salary,
                                                                                                   area)
{
    setYearsOfExperience(yearsOfExperience);
}

void AreaManager::setYearsOfExperience(int yearsOfExperience) throw(const char*)
{
    if(yearsOfExperience < 0 )
    {
        throw "ERROR: yearOfExperience cannot be negative";
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


