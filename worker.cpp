//
// Created by Amit Levy on 07/10/17.
//

#include <iostream>
using namespace std;

#include <string.h>
#include "worker.h"
#include "area.h"

long Worker::idGenerator = 100000000;

//The order of methods called in the init line was change on purpose, setName is called last because of the name allocation.
//that way we don't need to worry that if an exception occurs, the destructor is not called.

Worker::Worker(const char *name, long idNumber, int salary, Area *area)
{
    generateID();
    setSalary(salary);
    setName(name);
}

Worker::~Worker()
{
    delete[](name);
}

const char *Worker::getName() const
{
    return name;
}

long Worker::getIdNumber() const
{
    return idNumber;
}

int Worker::getSalary() const
{
    return salary;
}

void Worker::setSalary(int salary) throw(const char*)
{
    if(salary < 0)
    {
        throw "ERROR: idNumber cannot be negative";
    }
    this->salary = salary;
}

const Area &Worker::getArea() const
{
    return *area;
}

void Worker::setArea(Area &area)
{

    if((this->area == nullptr) || (this->area != &area))
    {
        this->area = &area;
        area.addWorker(*this);
    }
}

ostream& operator<<(ostream& os, const Worker& worker)
{
    os << "Worker details: \n Name: " << worker.getName() << "\n ID: " << worker.getIdNumber() << "\n Salary: " << worker.getSalary() << "\n Area: " << worker.getArea() << endl;

    worker.toOs(os);
}


void Worker::setName(const char *name) throw(const char*)
{
    if(!name)
    {
        throw "ERROR: worker's name is pointing to NULL";
    }

    if(strcmp(name,"") == 0)
    {
        throw "ERROR: worker's name cannot be empty";
    }
    this->name = strdup(name);
}

bool Worker::operator==(const Worker &other)
{
    return this->idNumber == other.idNumber;

}

void Worker::generateID()
{
    idNumber = idGenerator++;
}

