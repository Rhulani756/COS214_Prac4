
#ifndef PRAC_4_TRUCKLOGISTICSMANAGER_H
#define PRAC_4_TRUCKLOGISTICSMANAGER_H

#include "TruckObserver.h"
#include <vector>
#include <algorithm>
class TruckLogisticsManager {
private:
    std::vector<TruckObserver*> trucks;
public:
    TruckLogisticsManager();
    void buyTruck(TruckObserver* truck);
    void sellTruck(TruckObserver* truck);
    void callTruck(TruckObserver* truck, CropField* field);
};


#endif
