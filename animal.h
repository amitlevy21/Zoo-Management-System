//
//  Animal.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __ANIMAL_H
#define __ANIMAL_H

#include <iostream>

using namespace std;

class Area;

static const string animalClasses[] = {"LAND", "MARINE", "AMPHIBIAN"};

class Animal
{
public:

	enum class eAnimalClass{LAND, MARINE, AMPHIBIAN};

	Animal(const string& name, float weight, int birthYear, eAnimalClass animalClass);

	Animal(const Animal& animal) = delete;

	const Animal& operator=(const Animal& animal) = delete;

	bool operator==(const Animal& other);

	virtual inline const string& getName() 	const;

	virtual inline float getWeight() 		const;

	virtual inline int getBirthYear() 		const;

	inline Animal::eAnimalClass getAnimalClass() 	const;

	void setArea(Area& area);

	virtual void toOs(ostream& os) const = 0;

	friend ostream& operator<<(ostream& os, const Animal& animal);

	virtual const string& getClassName() const = 0;

private:
	string name;
	float weight;
	int birthYear;
	Area* area;
	eAnimalClass animalClass;

	void setName(const string& name) 		throw (const string&);
	void setWeight(float weight) 			throw (const string&);
	void setBirthYear(int birthYear) 		throw (const string&);
};

#endif /* __ANIMAL_H */
