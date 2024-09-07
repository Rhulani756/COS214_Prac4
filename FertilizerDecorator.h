

#ifndef PRAC_4_FERTILIZERDECORATOR_H
#define PRAC_4_FERTILIZERDECORATOR_H

#include "CropFieldDecorator.h"

class FertilizerDecorator : public CropFieldDecorator {
public:
    FertilizerDecorator(CropField* field, int capacity) : CropFieldDecorator(field) {}

    // Override methods from CropField
    int harvest() override;
    void rain() override;

    // Corrected the method name to match the one in the truck class
    void increaseProduction() override;
    int getChildCount() override {
        return 0;  // FertilizerDecorator does not add child units
    }
    int getLeftOverCapacity() override;

    ~FertilizerDecorator() override;
};

#endif