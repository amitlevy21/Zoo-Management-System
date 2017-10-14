#ifndef __LION_H
#define __LION_H

#include "animal.h"

static const string maneColors[] = {"WHITE", "BROWN", "YELLOW", "RED", "ORANGE"};

class Lion : public Animal
{
    
public:
	enum eManeColor { WHITE, BROWN, YELLOW, RED, ORANGE };

	Lion(const string& name, float weight, int birthYear, eManeColor maneColor, eAnimalClass animalClass);
    
    Lion(const Lion& lion) = delete;
    const Lion& operator=(const Lion& lion) = delete;
    
    inline eManeColor getManeColor() const;
    
	virtual void toOs(ostream& os) const override;

	virtual const string& getClassName() const override ;

private:
	eManeColor maneColor;
};


#endif /* __LION_H */
