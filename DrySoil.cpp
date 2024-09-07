// DrySoil.cpp
#include "DrySoil.h"
#include "FruitfulSoil.h"

int DrySoil::harvestCrops(int baseYield) {
    return baseYield * 1;  // Minimal crop yield in dry soil
}

SoilState* DrySoil::rain() {
    return new FruitfulSoil();  // Transition to FruitfulSoil after rain
}

std::string DrySoil::getName() {
    return "Dry";  // Return the name of this soil state
}
