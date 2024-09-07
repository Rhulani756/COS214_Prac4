#include "FertilizerDecorator.h"

// Harvest crops with increased production due to fertilizer
int FertilizerDecorator::harvest() {
    return wrappedField->harvest();  // Delegate to the wrapped field
}

// Handle rain, possibly transitioning the soil state
void FertilizerDecorator::rain() {
    wrappedField->rain();  // Delegate to the wrapped field
}

// Increase production (correct method name)
void FertilizerDecorator::increaseProduction() {
    wrappedField->increaseProduction();  // Increase production on the wrapped field
}

// Return the remaining capacity in the crop field
int FertilizerDecorator::getLeftOverCapacity() {
    return wrappedField->getLeftOverCapacity();  // Delegate to the wrapped field
}

// Destructor implementation
FertilizerDecorator::~FertilizerDecorator() {
    // Destructor logic if needed, wrappedField is handled elsewhere
}