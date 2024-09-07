
#ifndef PRAC_4_FLOODEDSOIL_H
#define PRAC_4_FLOODEDSOIL_H

#include "SoilState.h"
class FloodedSoil : public SoilState{
public:
    int harvestCrops(int baseYield) override;
    SoilState* rain() override;
    std::string getName() override;
};


#endif
