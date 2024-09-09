#include "TruckLogisticsManager.h"
#include <iostream>

TruckLogisticsManager::TruckLogisticsManager() {
    //Constructor
}
// Adds a new truck to the fleet
void TruckLogisticsManager::buyTruck(TruckObserver* truck) {
    trucks.push_back(truck);
    std::cout << "Truck bought and added to the fleet!" << std::endl;
}

// Removes a truck from the fleet
void TruckLogisticsManager::sellTruck(TruckObserver* truck) {
    // Remove the truck from the vector
    trucks.erase(std::remove(trucks.begin(), trucks.end(), truck), trucks.end());
    std::cout << "Truck sold and removed from the fleet!" << std::endl;
}

// Dispatches a specific truck to perform its task on a given CropField
void TruckLogisticsManager::callTruck(TruckObserver* truck, CropField* field) {
    if (std::find(trucks.begin(), trucks.end(), truck) != trucks.end()) {
        // Notify the truck to start its operation on the given field
        std::cout << "Truck dispatched to perform its task on the field!" << std::endl;
    } else {
        std::cout << "Truck not found in the fleet!" << std::endl;
    }
}
