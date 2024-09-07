
#ifndef PRAC_4_TRUCKOBSERVER_H
#define PRAC_4_TRUCKOBSERVER_H

#include "CropField.h"
class TruckObserver {
public:
    void update(CropField* field);
    void startEngin();
    ~TruckObserver();
};


#endif
