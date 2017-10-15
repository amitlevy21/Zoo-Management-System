#include <iostream>
#include "worker.h"
#include "area.h"
using namespace std;

long Worker::idGenerator = 100000000;

//The order of methods called in the init line was change on purpose, setName is called last because of the name allocation.
//that way we don't need to worry that if an exception occurs, the destructor is not called.

Worker::Worker(const string& name, int salary, Area *area)
{
    generateID();
    setSalary(salary);
    setName(name);
    setArea(*area);
}

inline const string& Worker::getName() const
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

void Worker::setSalary(int salary) throw(const string&)
{
    if(salary < 0)
    {
        throw "salary cannot be negative";
    }

    this->salary = salary;
}

const Area& Worker::getArea() const
{
    return *area;
}

void Worker::setArea(Area &area)
{

    if((this->area == nullptr) || (this->area != &area))
    {
        if(&area)
        {
            this->area = &area;
            area.addWorker(*this);
        }
    }
}

ostream& operator<<(ostream& os, const Worker& worker)
{
    os << "name: " << worker.getName().c_str() << ", ID: " << worker.getIdNumber() << ", salary: " << worker.getSalary() << ", area: " << worker.getArea().getName();

    worker.toOs(os);

    return os;
}


void Worker::setName(const string& name) throw(const string&)
{
    if(name.empty())
    {
        throw "worker's name cannot be empty";
    }
    this->name = name;
}

bool Worker::operator==(const Worker &other)
{
    return this->idNumber == other.idNumber;
}

void Worker::generateID()
{
    idNumber = idGenerator++;
}

