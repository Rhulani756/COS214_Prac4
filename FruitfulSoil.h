
#ifndef PRAC_4_FRUITFULSOIL_H
#define PRAC_4_FRUITFULSOIL_H

#include "SoilState.h"
class FruitfulSoil : public SoilState{
public:
    int harvestCrops(int baseYield) override;
    SoilState* rain() override;
    std::string getName() override;
};


#endif
