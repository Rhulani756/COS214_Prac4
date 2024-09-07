// FloodedSoil.cpp
#include "FloodedSoil.h"
#include <iostream>

int FloodedSoil::harvestCrops(int baseYield) {
    // In flooded soil, no crops can be harvested
    std::cout << "No crops can be harvested due to flooded soil!" << std::endl;
    return 0;  // No yield in flooded soil
}

SoilState* FloodedSoil::rain() {
    // The soil is already flooded, so additional rain doesn't change the state
    std::cout << "The soil is already flooded, rain has no further effect!" << std::endl;
    return this;  // Stay in the flooded state
}

std::string FloodedSoil::getName() {
    return "Flooded";  // Return the name of this soil state
}
