// ExtraBarnDecorator.cpp
#include "ExtraBarnDecorator.h"

ExtraBarnDecorator::ExtraBarnDecorator(CropField* field, int capacity)
        : CropFieldDecorator(field), extraCapacity(capacity) {}

// Returns the total capacity including the extra barn's capacity
int ExtraBarnDecorator::getTotalCapacity() {
    return wrappedField->getTotalCapacity();
}

// Returns the leftover storage capacity including the extra barn's capacity
int ExtraBarnDecorator::getLeftOverCapacity() {
    return wrappedField->getTotalCapacity() + extraCapacity;
}

// Delegates the harvest method to the wrapped crop field
int ExtraBarnDecorator::harvest() {
    return wrappedField->harvest();  // Harvest as usual
}

// Delegates the rain method to the wrapped crop field
void ExtraBarnDecorator::rain() {
    wrappedField->rain();  // Rain as usual
}

// Destructor to clean up any resources if needed
ExtraBarnDecorator::~ExtraBarnDecorator() {
    // Destructor logic if necessary
}

