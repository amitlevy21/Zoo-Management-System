#ifndef __GIRAFFE_H
#define __GIRAFFE_H

#include "animal.h"

class Giraffe : public Animal
{

private:
    float lengthOfNeck;

	void setLengthOfNeck(float lengthOfNeck) throw (const string&);
    
public:
	Giraffe(const string& name, float weight, int birthYear, float lengthOfNeck, eAnimalClass animalClass);
    
    Giraffe(const Giraffe& giraffe) = delete;
    const Giraffe& operator=(const Giraffe& giraffe) = delete;
    
    inline float getLengthOfNeck() const;
    
	virtual void toOs(ostream& os) const override;

	virtual const string& getClassName() const override ;
};

#endif /* __GIRAFFE_H */
