#ifndef ZOO_MANAGEMENT_SYSTEM_OBSERVERINTERFACE_H
#define ZOO_MANAGEMENT_SYSTEM_OBSERVERINTERFACE_H

#include "animal.h"

class Observer
{
public:
    virtual void notify(const Animal &animalAdded) = 0;
    virtual ~Observer() = default;
};

#endif //ZOO_MANAGEMENT_SYSTEM_OBSERVERINTERFACE_H
