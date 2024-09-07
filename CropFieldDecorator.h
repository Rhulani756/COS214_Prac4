
#ifndef PRAC_4_CROPFIELDDECORATOR_H
#define PRAC_4_CROPFIELDDECORATOR_H

#include "CropField.h"
class CropFieldDecorator {
private:
    CropField* wrappedField;
public:
    CropFieldDecorator(CropField* field);
    int harvest;
    int getTotalCapacity();
    int getLeftOverCapacity();
    void increaseProduction();
    ~CropFieldDecorator();
};


#endif
