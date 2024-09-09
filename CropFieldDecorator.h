
#ifndef PRAC_4_CROPFIELDDECORATOR_H
#define PRAC_4_CROPFIELDDECORATOR_H

#include "CropField.h"
class CropFieldDecorator: public CropField{
protected:
    CropField* wrappedField;
public:
    CropFieldDecorator(CropField* field);
    int harvest() override;
    int getTotalCapacity() override;
    virtual ~CropFieldDecorator() = 0;

    std::string getCropType();

    std::string getSoilStateName();
};


#endif
