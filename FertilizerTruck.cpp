#include "FertilizerTruck.h"
#include "FertilizerDecorator.h"  // Include FertilizerDecorator to use it
#include <iostream>
FertilizerTruck::FertilizerTruck() {
    //Constructor
}

void FertilizerTruck::update(CropField* field) {
    // Check if the crop field has dry soil and needs fertilization
    if (field->getSoilStateName() == "Dry") {
        std::cout << "Field " << field->getCropType() << " needs fertilizer!" << std::endl;
        startEngine();  // Start the truck to deliver fertilizer

        // Apply the FertilizerDecorator to enhance crop production
        FertilizerDecorator* fertilizedField = new FertilizerDecorator(field, 0);
        fertilizedField->increaseProduction();  // Use the correct method to increase production
        delete fertilizedField;
    } else {
        std::cout << "Field " << field->getCropType() << " does not need fertilizer." << std::endl;
    }
}

void FertilizerTruck::startEngine() {
    std::cout << "Fertilizer truck engine started. Delivering fertilizer!" << std::endl;
}

FertilizerTruck::~FertilizerTruck() {
    // Destructor logic if needed
}
