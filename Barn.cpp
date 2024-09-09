#include "Barn.h"
#include <stdexcept>
#include <sstream>

// Constructor that initializes the barn with a storage capacity
Barn::Barn(int capacity) : storageCapacity(capacity) {
    cropType = "Unknown";  // Default crop type is "Unknown"
}

// Adding units to the Barn is not supported, so we throw an exception
void Barn::add(FarmUnit* unit) {
    throw std::logic_error("Barn does not support adding units.");
}

// Removing units from the Barn is not supported, so we throw an exception
void Barn::remove(FarmUnit* unit) {
    throw std::logic_error("Barn does not support removing units.");
}

// Barn does not have children, so we throw an exception for this method
FarmUnit* Barn::getChild(int index) {
    throw std::out_of_range("Barn does not have children.");
}

// Returns the name of this unit
std::string Barn::getName() {
    return "Barn";
}

// Returns the total storage capacity of the barn
int Barn::getTotalCapacity() {
    return storageCapacity;
}

// Returns the type of crop stored in the barn
std::string Barn::getCropType() {
    return cropType;
}

// Destructor, no specific cleanup needed in this case
Barn::~Barn() {
    // Cleanup logic if necessary
}
