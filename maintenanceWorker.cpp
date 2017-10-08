//
// Created by Amit Levy on 07/10/17.
//

#include "maintenanceWorker.h"

MaintenanceWorker::MaintenanceWorker(const char *name, long idNumber, int salary, float shoeSize) : Worker(name, idNumber, salary)
{
    setShoeSize(shoeSize);
}

float MaintenanceWorker::getShoeSize() const
{
    return shoeSize;
}

void MaintenanceWorker::setShoeSize(float shoeSize)
{
    if(shoeSize < 0 )
    {
        throw "ERROR: shoeSize cannot be negative";
    }
    this->shoeSize = shoeSize;
}

void MaintenanceWorker::toOs(ostream &os) const
{
    os << "Maintenance Worker Details:\n Shoe Size: " << shoeSize;
}
