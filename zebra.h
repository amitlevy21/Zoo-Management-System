#ifndef __ZEBRA_H
#define __ZEBRA_H

#include "animal.h"

class Zebra : virtual public Animal
{
private:
    int numOfStripes;

	void setNumOfStripes(int numOfStripes) throw (const string&);
    
public:
	Zebra(const string& name, float weight, int birthYear, int numOfStripes, eAnimalClass animalClass);

    Zebra(const Zebra& zebra) = delete;
    const Zebra& operator=(const Zebra& zebra) = delete;
    
    inline int getNumOfStripes() const;
    
	virtual void toOs(ostream& os) const override;

	virtual const string& getClassName() const override ;
};


#endif /* __ZEBRA_H */
