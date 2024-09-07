// CropField.cpp
#include "CropField.h"
#include <algorithm>

CropField::CropField(std::string crop, int capacity, SoilState* initialState)
        : cropType(crop), storageCapacity(capacity), amountStored(0), soilState(initialState), baseYield(10) {}

int CropField::getTotalCapacity() {
    return storageCapacity;  // Return the total storage capacity of the field
}

std::string CropField::getCropType() {
    return cropType;  // Return the type of crop (e.g., wheat, corn)
}

std::string CropField::getSoilStateName() {
    return soilState->getName();  // Return the name of the current soil state
}

int CropField::harvest() {
    int harvestedAmount = soilState->harvestCrops(baseYield);  // Harvest based on soil state and base yield
    amountStored += harvestedAmount;  // Add harvested amount to the stored crops
    notify();  // Notify trucks after the harvest
    return harvestedAmount;
}

void CropField::rain() {
    SoilState* newState = soilState->rain();  // Change the soil state based on rain
    delete soilState;  // Clean up the old state
    soilState = newState;  // Update to the new soil state
}

int CropField::getLeftOverCapacity() {
    return storageCapacity - amountStored;  // Return remaining storage capacity
}

void CropField::increaseProduction() {
    baseYield *= 2;  // Increase crop yield (e.g., due to fertilizer)
}

void CropField::attach(TruckObserver* observer) {
    observers.push_back(observer);  // Attach a truck observer to the crop field
}

void CropField::detach(TruckObserver* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());  // Detach the truck observer
}

void CropField::notify() {
    for (TruckObserver* observer : observers) {
        observer->update(this);  // Notify all attached observers
    }
}

void CropField::add(FarmUnit* unit) {
    // No implementation needed as CropField is a leaf node in the farm structure
}

void CropField::remove(FarmUnit* unit) {
    // No implementation needed as CropField is a leaf node in the farm structure
}

FarmUnit* CropField::getChild(int index) {
    return nullptr;  // CropField has no child units
}
SoilState* CropField::getSoilState() const {
    return soilState;
}

std::string CropField::getName() {
    return "CropField";  // Return a meaningful name or field-specific name
}
CropField::~CropField() {
    delete soilState;  // Clean up the soil state upon destruction
}
