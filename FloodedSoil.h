
#ifndef PRAC_4_FLOODEDSOIL_H
#define PRAC_4_FLOODEDSOIL_H

#include "SoilState.h"
class FloodedSoil {
    int harvestCrops(int baseYield);
    SoilState* rain();
    std::string getName();
};


#endif
