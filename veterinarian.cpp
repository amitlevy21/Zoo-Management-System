//
// Created by Amit Levy on 07/10/17.
//

#include "veterinarian.h"

Veterinarian::Veterinarian(const string& name, int salary, int licenseNumber, Area *area)
        : Worker(name, salary, area)
{
    setLicenseNumber(licenseNumber);
}

void Veterinarian::setLicenseNumber(int licenseNumber) throw(const string&)
{
    if(licenseNumber < 0)
    {
        throw "ERROR: licenseNumber cannot be negative";
    }
    this->licenseNumber = licenseNumber;
}

int Veterinarian::getLicenseNumber() const
{
    return licenseNumber;
}

void Veterinarian::toOs(ostream &os) const
{
    os << "Veterinarian details:" << endl << "License Number: " << licenseNumber;
}

const string& Veterinarian::getWorkerType() const
{
    return "Veterinarian";
}

