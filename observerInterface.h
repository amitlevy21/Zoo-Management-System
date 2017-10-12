//
// Created by Amit Levy on 12/10/17.
//

#ifndef ZOO_MANAGEMENT_SYSTEM_OBSERVERINTERFACE_H
#define ZOO_MANAGEMENT_SYSTEM_OBSERVERINTERFACE_H

#include "animal.h"

class Observer
{
public:
    virtual void notify(Animal &animalAdded) = 0;
};

#endif //ZOO_MANAGEMENT_SYSTEM_OBSERVERINTERFACE_H
