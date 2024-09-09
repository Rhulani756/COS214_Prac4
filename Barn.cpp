#include "Barn.h"
#include <stdexcept>
#include <sstream>

Barn::Barn(int capacity) : storageCapacity(capacity) {}

void Barn::add(FarmUnit* unit) {
    throw std::logic_error("Barn does not support adding units.");
}

void Barn::remove(FarmUnit* unit) {
    throw std::logic_error("Barn does not support removing units.");
}

FarmUnit* Barn::getChild(int index) {
    throw std::out_of_range("Barn does not have children.");
}

int Barn::getChildCount() {
    return 0;  // Barn does not have children
}

std::string Barn::getName() {
    return "Barn";
}

int Barn::getTotalCapacity() {
    return storageCapacity;
}

std::string Barn::getCropType() {
    return "None";  // Assuming Barn does not store crops
}

std::string Barn::getSoilStateName() {
    return "Unknown";  // Assuming Barn does not handle soil
}

int Barn::harvest() {
    return 0;  // Assuming no crops are harvested from Barn
}

Barn::~Barn() {
    // Cleanup if necessary
}
