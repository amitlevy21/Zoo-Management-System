//
// Created by Amit Levy on 07/10/17.
//

#include "Veterinarian.h"

Veterinarian::Veterinarian(const char *name, long idNumber, int salary, int licenseNumber) : Worker(name, idNumber, salary), setLicenseNumber(licenseNumber)
{

}

void Veterinarian::setLicenseNumber(int licenseNumber)
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
    os << "Veterinarian details:\n License Number: " << licenseNumber;
}

