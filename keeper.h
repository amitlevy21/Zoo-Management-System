#ifndef __KEEPER_H
#define __KEEPER_H

#include "worker.h"
#include "observerInterface.h"

static const string eAnimalString[] = {"Lion" , "Penguin", "Elephant", "Giraffe", "Zebra", "Horse", "Zebroid"};

class Keeper : public Worker, public Observer
{
    
public:
	enum eAnimalSpeciality { LION, PENGUIN, ELEPHANT, GIRAFFE, ZEBRA, HORSE, ZEBROID};

	Keeper(const string& name, int salary, eAnimalSpeciality keeperSpecialty, Area *area = nullptr);

    Keeper(const Keeper& keeper) = delete;
    const Keeper& operator=(const Keeper& keeper) = delete;
    
    inline eAnimalSpeciality getKeeperSpecialty() const;
    
	virtual void toOs(ostream& os) const override;

	virtual const string& getWorkerType() const override;

    inline int getNumOfAnimalsToTakeCare() const;

	void notify(const Animal& animalAdded) override;

private:
	eAnimalSpeciality keeperSpecialty;
    int numOfAnimalsToTakeCare = 0;
};



#endif /* __KEEPER_H */
