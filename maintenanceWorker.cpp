//
// Created by Amit Levy on 07/10/17.
//

#include "maintenanceWorker.h"

MaintenanceWorker::MaintenanceWorker(const string& name, int salary, float shoeSize, Area *area)
        : Worker(name, salary, area)
{
    setShoeSize(shoeSize);
}

float MaintenanceWorker::getShoeSize() const
{
    return shoeSize;
}

void MaintenanceWorker::setShoeSize(float shoeSize) throw(const string&)
{
    if(shoeSize < 0 )
    {
        throw "ERROR: shoeSize cannot be negative";
    }
    this->shoeSize = shoeSize;
}

void MaintenanceWorker::toOs(ostream &os) const
{
    os << "Maintenance Worker Details:"<<endl<<"Shoe Size: " << shoeSize;
}

const string& MaintenanceWorker::getWorkerType() const {
    return "Maintenance Worker";
}
