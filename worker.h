#ifndef __WORKER_H
#define __WORKER_H

#include <iostream>
using namespace std;

class Area;

class Worker
{
    
private:
	static long idGenerator;
	string name;
    long idNumber;
    int salary;
	Area* area;

	void generateID();

public:
	Worker(const string& name, int salary, Area *area = nullptr);
    
    Worker(const Worker& worker) = delete;
    const Worker& operator=(const Worker& worker) = delete;

	bool operator==(const Worker& other);
    
    inline const string& getName() const;
	void setName(const string& name) throw(const string&);
    
    inline long getIdNumber() const;
    
    inline int getSalary() const;
    void setSalary(int salary) throw (const string&);
    
    inline const Area& getArea() const;
    void setArea(Area &area);
    
	virtual void toOs(ostream& os) const = 0;
    friend ostream& operator<<(ostream& os, const Worker& worker);

	virtual const string& getWorkerType() const = 0;
};




#endif /* __WORKER_H */
