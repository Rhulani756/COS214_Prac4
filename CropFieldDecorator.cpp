#include "CropFieldDecorator.h"

CropFieldDecorator::CropFieldDecorator(CropField* field)
        : CropField(field->getCropType(), field->getTotalCapacity(), field->getSoilState()),  // Call base class constructor
          wrappedField(field) {}

int CropFieldDecorator::getTotalCapacity() {
    return wrappedField->getTotalCapacity();
}

std::string CropFieldDecorator::getCropType() {
    return wrappedField->getCropType();
}

std::string CropFieldDecorator::getSoilStateName() {
    return wrappedField->getSoilStateName();
}

int CropFieldDecorator::harvest() {
    return wrappedField->harvest();
}

CropFieldDecorator::~CropFieldDecorator() {
    //delete wrappedField;  // Clean up the wrapped field
}
