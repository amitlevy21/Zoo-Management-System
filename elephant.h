#ifndef __ELEPHANT_H
#define __ELEPHANT_H

#include "animal.h"
#include "area.h"

class Elephant : public Animal
{

private:
    float sizeOfEars;
    float lengthOfTrunk;

	void setSizeOfEars(float sizeOfEars) 		throw (const string&);
	void setLengthOfTrunk(float lengthOfTrunk) 	throw (const string&);
    
public:
	Elephant(const string& name, float weight, int birthYear, float sizeOfEars, float lengthOfTrunk,
                 eAnimalClass animalClass);
    
    Elephant(const Elephant& elephant) = delete;
    const Elephant& operator=(const Elephant& elephant) = delete;
    
    inline float getSizeOfEars() 	const;

    inline float getLengthOfTrunk() const;
    
	virtual void toOs(ostream& os) const override;

	virtual const string& getClassName() const override;
 
};

#endif /* __ELEPHANT_H */
