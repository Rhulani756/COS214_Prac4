

#ifndef PRAC_4_FERTILIZERTRUCK_H
#define PRAC_4_FERTILIZERTRUCK_H


#include "CropField.h"
class FertilizerTruck {
public:
    void update(CropField* field);
    void startEngine();
    ~FertilizerTruck();
};


#endif
