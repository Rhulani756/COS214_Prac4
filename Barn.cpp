
#include "Barn.h"

Barn::Barn(int capacity) : storageCapacity(capacity) {}

int Barn::getTotalCapacity() {
    return storageCapacity;
}

std::string Barn::getCropType() {
    return "Barn has no crops";
}

std::string Barn::getSoilStateName() {
    return "Barn has no soil";
}

void Barn::add(FarmUnit* unit) {

}

void Barn::remove(FarmUnit* unit) {

}

FarmUnit* Barn::getChild(int index) {
    return nullptr;
}

Barn::~Barn() {

}
