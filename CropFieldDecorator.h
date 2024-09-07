
#ifndef PRAC_4_CROPFIELDDECORATOR_H
#define PRAC_4_CROPFIELDDECORATOR_H

#include "CropField.h"
class CropFieldDecorator: public CropField{
protected:
    CropField* wrappedField;
public:
    CropFieldDecorator(CropField* field);
    int harvest() override;
    std::string getCropType() override;
    std::string getSoilStateName() override;
    int getTotalCapacity() override;
    int getLeftOverCapacity() override;
    void increaseProduction() override;
    int getChildCount() override {
        return 0;  // CropFieldDecorator does not add child units
    }
    ~CropFieldDecorator() override;
};


#endif
