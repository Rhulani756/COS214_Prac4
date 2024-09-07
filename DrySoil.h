
#ifndef PRAC_4_DRYSOIL_H
#define PRAC_4_DRYSOIL_H

#include "SoilState.h"
class DrySoil: public SoilState {
public:
    int harvestCrops(int baseYield) override;
    SoilState* rain() override;
    std::string getName() override;
};


#endif
