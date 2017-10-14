#ifndef __PENGUIN_H
#define __PENGUIN_H

#include "animal.h"

static const string seaFood[] = {"SHRIMP", "CRAB", "FISH", "CALAMARI"};

class Penguin : public Animal
{

public:
	enum eSeaFood { SHRIMP, CRAB, FISH, CALAMARI };

	Penguin(const string& name, float weight, int birthYear, eSeaFood favoriteFood, eAnimalClass animalClass);
    
    Penguin(const Penguin& penguin) = delete;
    const Penguin& operator=(const Penguin& penguin) = delete;
    
    inline eSeaFood getFavoriteFood() const;

	virtual void toOs(ostream& os) const override;

	virtual const string& getClassName() const override ;

private:
	eSeaFood favoriteFood;
};


#endif /* __PENGUIN_H */
