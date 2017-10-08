//
// Created by Amit Levy on 07/10/17.
//

#include "areaManager.h"

//set Area?
AreaManager::AreaManager(const char *name, long idNumber, int salary, int yearsOfExperience) : Worker(name, idNumber, salary)
{
    setYearsOfExperience(yearsOfExperience);
}

void AreaManager::setYearsOfExperience(int yearsOfExperience)
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
    os << "Area Manager Details:\n Years of Experience: " << yearsOfExperience;
}


