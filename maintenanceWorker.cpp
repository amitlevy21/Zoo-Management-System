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
        throw "shoeSize cannot be negative";
    }
    this->shoeSize = shoeSize;
}

void MaintenanceWorker::toOs(ostream &os) const
{
    os << ", shoe size: " << shoeSize;
}

const string& MaintenanceWorker::getWorkerType() const
{
    return "Maintenance Worker";
}
