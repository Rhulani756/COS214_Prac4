// FruitfulSoil.cpp
#include "FruitfulSoil.h"
#include "FloodedSoil.h"
#include <iostream>

int FruitfulSoil::harvestCrops(int baseYield) {
    // In fruitful soil, the yield is tripled
    std::cout << "Harvesting crops in fruitful soil!" << std::endl;
    return baseYield * 3;  // Triple the yield in fruitful soil
}

SoilState* FruitfulSoil::rain() {
    // If it rains too much, the soil may become flooded
    std::cout << "Too much rain! The soil has become flooded!" << std::endl;
    return new FloodedSoil();  // Transition to flooded soil state
}

std::string FruitfulSoil::getName() {
    return "Fruitful";  // Return the name of this soil state
}
