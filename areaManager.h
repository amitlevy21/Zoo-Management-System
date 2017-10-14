#ifndef __AREA_MANAGER_H
#define __AREA_MANAGER_H

#include "worker.h"

class AreaManager: public Worker
{
private:
	int yearsOfExperience;

	void setYearsOfExperience(int yearsOfExperience) throw (const string&);

public:
	AreaManager(const string& name, int salary, int yearsOfExperience, Area *area = nullptr);
    
    AreaManager(const AreaManager& areaManager) = delete;
    const AreaManager& operator=(const AreaManager& areaManager) = delete;

	inline int getYearsOfExperience() 	const;

	virtual void toOs(ostream& os) 		const;

	virtual const string& getWorkerType() const override;
};


#endif /* __AREA_MANAGER_H */
