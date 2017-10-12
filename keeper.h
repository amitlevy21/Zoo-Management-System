//
//  Keeper.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __KEEPER_H
#define __KEEPER_H

#include "worker.h"
#include "animal.h"
#include "observerInterface.h"

static const char* const eAnimalString[] = {"Lion" , "Penguin", "Elephant", "Giraffe", "Zebra", "Horse", "Zebroid"};

class Keeper : public Worker, public Observer
{
    
public:
	enum eAnimalSpeciality { LION, PENGUIN, ELEPHANT, GIRAFFE, ZEBRA, HORSE, ZEBROID};

	Keeper(const char *name, int salary, eAnimalSpeciality keeperSpecialty, Area *area = nullptr);

    Keeper(const Keeper& keeper) = delete;
    const Keeper& operator=(const Keeper& keeper) = delete;
    
    inline eAnimalSpeciality getKeeperSpecialty() const;
    
	virtual void toOs(ostream& os) const override;

	virtual const char* getWorkerType() const override;

    inline int getNumOfAnimalsToTakeCare() const;

	void notify(Animal& animalAdded) override;

private:
	eAnimalSpeciality keeperSpecialty;
    int numOfAnimalsToTakeCare = 0;
};



#endif /* __KEEPER_H */
