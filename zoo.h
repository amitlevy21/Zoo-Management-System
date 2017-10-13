//
//  Zoo.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 18/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __ZOO_H
#define __ZOO_H

#include "worker.h"
#include "animal.h"
#include "area.h"
#include <vector>


using namespace std;

class Zoo
{
private:
	string name;
    int maxNumOfAreas;
    int numOfAreas =0;
    vector<Area*> areas;
	Area& quarantineArea;

	void setMaxNumOfAreas(int maxNumOfAreas) throw (const string&);
	void setName(const string& name) throw(const string&);


	Zoo(const string& name, int maxNumOfAreas, Area& quarantineArea);
	static Zoo* theZoo;

public:

	static Zoo* getInstance(const string& name, int maxNumOfAreas, Area& quarantineArea);
    ~Zoo();

	Zoo(const Zoo& other) = delete;
	const Zoo& operator=(const Zoo& zoo) = delete;
    
    const string& getName() const;
    
    int getMaxNumOfAreas() const;

    int getNumOfAreas() const;
	
	const Area& getQuarantineAreaArea() const;
    
	void addArea(Area& area)  throw (const string&);
    
	void addAnimal(Animal& animal, Area& area)  throw (const string&);
    
	void addWorker(Worker& worker, Area& area)  throw (const string&);
    
    const vector<Area*> getAllAreas() const;

	vector<Area*> getAllAreas();
    
    const Zoo& operator+=(Area& area);
    
    const Area& operator[](int index) const throw(const string&);

	int findAreaIndex(const Area &area) const;
    
    friend ostream& operator<<(ostream& os, const Zoo& zoo);
};




#endif /* __ZOO_H */
