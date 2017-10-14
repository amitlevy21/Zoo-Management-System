#ifndef __VETERINARIAN_H
#define __VETERINARIAN_H

#include "worker.h"

class Veterinarian : public Worker
{
private:
    int licenseNumber;

	void setLicenseNumber(int licenseNumber) throw (const string&);

public:
	Veterinarian(const string& name, int salary, int licenseNumber, Area *area = nullptr);
    
    Veterinarian(const Veterinarian& veterinarian) = delete;
    const Veterinarian& operator=(const Veterinarian& veterinarian) = delete;
    
	inline int getLicenseNumber() const;
    
	virtual void toOs(ostream& os) const override;

	virtual const string& getWorkerType() const override;
    
};




#endif /* __VETERINARIAN_H */
