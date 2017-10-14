#ifndef __MAINTENANCE_WORKER_H
#define __MAINTENANCE_WORKER_H

#include "worker.h"

class MaintenanceWorker : public Worker
{
private:
	float shoeSize;

public:
	MaintenanceWorker(const string& name, int salary, float shoeSize, Area *area = nullptr);
    
    MaintenanceWorker(const MaintenanceWorker& maintenanceWorker) = delete;
    const MaintenanceWorker& operator=(const MaintenanceWorker& maintenanceWorker) = delete;

	float getShoeSize() const;
	void setShoeSize(float shoeSize) throw (const string&);

	virtual void toOs(ostream& os) const override;

    virtual const string& getWorkerType() const override;
    
};




#endif /* __MAINTENANCE_WORKER_H */
