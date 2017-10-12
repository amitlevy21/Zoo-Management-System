//
//  Donkey.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __HOURSE_H
#define __HOURSE_H

#include "animal.h"

class Horse : virtual public Animal
{

private:
    float sizeOfHorseShoe;

	void setSizeOfHorseShoe(float sizeOfHorseShoe) throw (const char*);
    
public:
	Horse(const char *name, float weight, int birthYear, float sizeOfHorseShoe, eAnimalClass animalClass);

    Horse(const Horse& horse) = delete;
    const Horse& operator=(const Horse& horse) = delete;
    
    inline float getSizeOfHorseShoe() const;
    
	virtual void toOs(ostream& os) const override;

	virtual const char* getClassName() const override ;
};


#endif /* __HOURSE_H */
