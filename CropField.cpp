
#include "CropField.h"

CropField::CropField() {

}

int CropField::getTotalCapacity() {
    return 0;
}

std::string CropField::getCropType() {
    return std::string();
}

std::string CropField::getSoilTypeName() {
    return std::string();
}

int CropField::harvest() {
    return 0;
}

void CropField::rain() {

}

int CropField::getLeftOverCapacity() {
    return 0;
}

void CropField::increaseProduction() {

}

void CropField::attach(TruckObserver *observer) {

}

void CropField::detach(TruckObserver *observer) {

}

void CropField::notify() {

}

void CropField::add(FarmUnit *unit) {

}

FarmUnit *CropField::getChild(int index) {
    return nullptr;
}

std::string CropField::getName() {
    return std::string();
}

std::vector<FarmUnit *> CropField::getUnits() {
    return std::vector<FarmUnit *>();
}

CropField::~CropField() {

}
