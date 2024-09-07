
#ifndef PRAC_4_DRYSOIL_H
#define PRAC_4_DRYSOIL_H

#include "SoilState.h"
class DrySoil {
public:
    int harvestCrops(int baseYield);
    SoilState* rain();
    std::string getName();
};


#endif
