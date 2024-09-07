
#ifndef PRAC_4_TRUCKOBSERVER_H
#define PRAC_4_TRUCKOBSERVER_H


//#include "CropField.h"
class CropField;

class TruckObserver {
public:
    virtual void update(CropField* field) = 0;
    virtual void startEngine() = 0;
    virtual ~TruckObserver() = default;
};

#endif