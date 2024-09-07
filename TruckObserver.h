
#ifndef PRAC_4_TRUCKOBSERVER_H
#define PRAC_4_TRUCKOBSERVER_H

#include <vector>
class CropField;
//#include "TruckLogisticsManager.h"
//#include "FertilizerDecorator.h"
//#include "ExtraBarnDecorator.h"
class TruckObserver {
public:
    void update(CropField* field);
    void startEngin();
    ~TruckObserver();
};


#endif
