

#ifndef PRAC_4_FERTILIZERDECORATOR_H
#define PRAC_4_FERTILIZERDECORATOR_H

#include "CropFieldDecorator.h"
class FertilizerDecorator {
    FertilizerDecorator(CropField* field , int capacity);
    int harvest();
    void rain();
    int increaseProduct();
    int getLeftOverCapacity();
    ~FertilizerDecorator();
};


#endif
