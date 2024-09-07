

#ifndef PRAC_4_DELIVERYTRUCK_H
#define PRAC_4_DELIVERYTRUCK_H

#include "CropField.h"
class DeliveryTruck {
public:
    void update(CropField* field);
    void startEngine();
    ~DeliveryTruck();
};


#endif