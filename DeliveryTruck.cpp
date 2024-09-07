// DeliveryTruck.cpp
#include "DeliveryTruck.h"
#include <iostream>

void DeliveryTruck::update(CropField* field) {
    // Check if the crop field is nearing capacity and trigger the delivery
    if (field->getLeftOverCapacity() <= 20) {  // Example threshold for full capacity
        std::cout << "Storage almost full. Dispatching delivery truck to collect crops from field: "
                  << field->getCropType() << std::endl;
        startEngine();  // Start the delivery operation
    }
}

void DeliveryTruck::startEngine() {
    std::cout << "Delivery truck engine started. Collecting crops!" << std::endl;
}

DeliveryTruck::~DeliveryTruck() {

}
