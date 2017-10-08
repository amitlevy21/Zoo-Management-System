//
// Created by Amit Levy on 07/10/17.
//

#include <iostream>
using namespace std;

#include <string.h>
#include "Worker.h"



Worker::Worker(const char *name, long idNumber, int salary, const Area *area)
{

    //setName is called last because of the name allocation.
    //that way we don't need to worry that if an exception occurs and the destructor is not called.
    setIdNumber(idNumber);
    setSalary(salary);
    setName(name);
    if(area)
    {
        setArea(*area);
    }
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

void Worker::setSalary(int salary)
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

void Worker::setArea(const Area &area)
{
    //TODO
    this->area = &area;
}

ostream& operator<<(ostream& os, const Worker& worker)
{
    os << "Worker details: \n Name: " << worker.getName() << "\n ID: " << worker.getIdNumber() << "\n Salary: " << worker.getSalary() << "\n Area: " << worker.getArea() << endl;

    worker.toOs(os);

}

void Worker::setIdNumber(long idNumber)
{
    if( idNumber < 0)
    {
        throw "ERROR: idNumber cannot be negative";
    }
    this->idNumber = idNumber;

}

void Worker::setName(const char *name)
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

