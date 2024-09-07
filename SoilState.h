
#ifndef PRAC_4_SOILSTATE_H
#define PRAC_4_SOILSTATE_H

#include <iostream>
class SoilState {
public:
    int harvestCrops(int baseYiled);
    SoilState* rain();
    std::string getName();
};


#endif
