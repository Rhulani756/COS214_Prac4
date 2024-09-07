
#ifndef PRAC_4_SOILSTATE_H
#define PRAC_4_SOILSTATE_H

#include <iostream>
#include <string>
class SoilState {
public:
 virtual  int harvestCrops(int baseYiled) = 0;
 virtual   SoilState* rain() = 0;
 virtual  std::string getName() = 0;
 virtual ~SoilState() = default;
};


#endif
