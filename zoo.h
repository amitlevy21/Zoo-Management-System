//
//  Zoo.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 18/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __ZOO_H
#define __ZOO_H

#include "area.h"
#include "worker.h"
#include "animal.h"

using namespace std;

class Zoo
{
private:
    char* name;
    int maxNumOfAreas;
    int numOfAreas =0;
    Area** areas;
	Area& quarantineArea;

	void setMaxNumOfAreas(int maxNumOfAreas) throw (const char*);
	void setName(const char* name) throw(const char*);

public:
	Zoo(const char* name, int maxNumOfAreas, Area& quarantineArea);
    ~Zoo();

	Zoo(const Zoo& other) = delete;
	const Zoo& operator=(const Zoo& zoo) = delete;
    
    const char* getName() const;
    
    int getMaxNumOfAreas() const;

    int getNumOfAreas() const;
	
	const Area& getQuarantineAreaArea() const;
    
	void addArea(Area& area)  throw (const char *);
    
	void addAnimal(Animal& animal, Area& area)  throw (const char*);
    
	void addWorker(Worker& worker, Area& area)  throw (const char*);
    
    const Area** getAllAreas() const;
    
    const Zoo& operator+=(Area& area);
    
    const Area& operator[](int index) const throw(const char*);

	int findAreaIndex(const Area &area) const;
    
    friend ostream& operator<<(ostream& os, const Zoo& zoo);
};




#endif /* __ZOO_H */
