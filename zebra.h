//
//  Zibra.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//
#ifndef __ZEBRA_H
#define __ZEBRA_H

#include "animal.h"

class Zebra : virtual public Animal
{
private:
    int numOfStripes;

	void setNumOfStripes(int numOfStripes) throw (const char*);
    
public:
	Zebra(const char *name, float weight, int birthYear, int numOfStripes, eAnimalClass animalClass);

    Zebra(const Zebra& zebra) = delete;
    const Zebra& operator=(const Zebra& zebra) = delete;
    
    inline int getNumOfStripes() const;
    
	virtual void toOs(ostream& os) const override;
    
};


#endif /* __ZEBRA_H */
