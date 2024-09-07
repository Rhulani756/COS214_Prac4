
#ifndef PRAC_4_TRUCKLOGISTICSMANAGER_H
#define PRAC_4_TRUCKLOGISTICSMANAGER_H

#include "TruckObserver.h"
class TruckLogisticsManager {
private:
    std::vector<TruckObserver*> trucks;
public:
    void buyTruck(TruckObserver* truck);
    void sellTruck(TruckObserver* truck);
    void callTruck(TruckObserver* truck);
};


#endif
