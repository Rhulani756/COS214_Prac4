/**
 * @file CropField.cpp
 * @brief Implements the CropField class which manages a crop field with different soil states and observers like trucks.
 */

#include "CropField.h"
#include <algorithm>

/**
 * @brief Constructor for CropField class.
 * 
 * This initializes the crop field with a crop type, a storage capacity, and an initial soil state.
 * 
 * @param crop The type of crop being planted.
 * @param capacity The storage capacity of the field.
 * @param initialState The initial state of the soil.
 */
// Constructor
CropField::CropField(std::string crop, int capacity, SoilState* initialState)
        : cropType(crop), storageCapacity(capacity), amountStored(0), soilState(initialState), baseYield(10) {}

/**
 * @brief Returns the total capacity of the crop field.
 * 
 * @return int The storage capacity of the field.
 */
// Override pure virtual methods
int CropField::getTotalCapacity() {
    return storageCapacity;  // Return the total storage capacity of the field
}
/**
 * @brief Gets the type of crop being grown.
 * 
 * @return std::string The crop type (e.g., wheat, corn).
 */
std::string CropField::getCropType() {
    return cropType;  // Return the type of crop (e.g., wheat, corn)
}
/**
 * @brief Gets the current soil state name.
 * 
 * @return std::string The name of the current soil state.
 */
std::string CropField::getSoilStateName() {
    return soilState->getName();  // Return the name of the current soil state
}
/**
 * @brief Harvests the crops based on the soil's current state.
 * 
 * The amount of crops harvested depends on the base yield and the current soil state. After harvesting,
 * the observer (e.g., trucks) are notified.
 * 
 * @return int The amount of crops harvested.
 */
int CropField::harvest() {
    int harvestedAmount = soilState->harvestCrops(baseYield);  // Harvest based on soil state and base yield
    amountStored += harvestedAmount;  // Add harvested amount to the stored crops
    notify();  // Notify trucks after the harvest
    return harvestedAmount;
}
/**
 * @brief Simulates rain and changes the soil state accordingly.
 * 
 * This method changes the soil state based on rainfall and deletes the old state.
 */
void CropField::rain() {
    SoilState* newState = soilState->rain();  // Change the soil state based on rain
    delete soilState;  // Clean up the old state
    soilState = newState;  // Update to the new soil state
}
/**
 * @brief Attaches a TruckObserver to this crop field.
 * 
 * This is part of the observer pattern, where trucks are notified of certain events in the crop field (e.g., after a harvest).
 * 
 * @param observer A pointer to the TruckObserver that should be notified.
 */
void CropField::attach(TruckObserver* observer) {
    observers.push_back(observer);  // Attach a truck observer to the crop field
}
/**
 * @brief Detaches a TruckObserver from this crop field.
 * 
 * @param observer A pointer to the TruckObserver that should no longer be notified.
 */
void CropField::detach(TruckObserver* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());  // Detach the truck observer
}
/**
 * @brief Notifies all attached observers (trucks) that an event has occurred.
 */
void CropField::notify() {
    std::cout << "Notified";
}
/**
 * @brief Adds a child unit to this crop field (for composite pattern).
 * 
 * @param unit A pointer to the child FarmUnit to add.
 */
void CropField::add(FarmUnit* unit) {
    units.push_back(unit);
}
/**
 * @brief Removes the last child unit from this crop field.
 */
void CropField::remove(FarmUnit* unit) {
    units.pop_back();
}
/**
 * @brief Gets a child unit of this crop field by index.
 * 
 * @param index The index of the child unit.
 * @return FarmUnit* A pointer to the child unit (returns nullptr as CropField has no children by default).
 */
FarmUnit* CropField::getChild(int index) {
    return nullptr;  // CropField has no child units
}
/**
 * @brief Gets the name of this crop field.
 * 
 * @return std::string The name of the crop field.
 */
std::string CropField::getName() {
    return "CropField";  // Return a meaningful name or field-specific name
}

/**
 * @brief Gets the current soil state object.
 * 
 * @return SoilState* A pointer to the current soil state.
 */
SoilState* CropField::getSoilState() const {
    return soilState;
}
/**
 * @brief Destructor for CropField, cleans up any allocated memory.
 */
// Destructor
CropField::~CropField() {
   // delete soilState // Clean up the soil state upon destruction
}
/**
 * @brief Gets the base yield of crops.
 * 
 * @return int The base yield value.
 */
int CropField::getBaseYield() {
    return baseYield;
}

/**
 * @brief Sets the base yield of crops.
 * 
 * @param yield The value to multiply the base yield by.
 */
void CropField::setBaseYield(int yield) {
    baseYield = baseYield*yield;
}