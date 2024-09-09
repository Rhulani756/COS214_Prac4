

#ifndef PRAC_4_FERTILIZERDECORATOR_H
#define PRAC_4_FERTILIZERDECORATOR_H

#include "CropFieldDecorator.h"

class FertilizerDecorator : public CropFieldDecorator {
public:
    FertilizerDecorator(CropField* field, int capacity) : CropFieldDecorator(field) {}

    // Override methods from CropField
    int harvest() override;
    void rain() ;

    // Corrected the method name to match the one in the truck class
    void increaseProduction() ;
    int getChildCount() {
        return 0;  // FertilizerDecorator does not add child units
    }
    int getLeftOverCapacity() ;

    ~FertilizerDecorator() override;
};

#endif