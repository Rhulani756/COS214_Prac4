

#ifndef PRAC_4_EXTRABARNDECORATOR_H
#define PRAC_4_EXTRABARNDECORATOR_H

#include "CropFieldDecorator.h"
class ExtraBarnDecorator {
private:
    int extraCapacity;
public:
    ExtraBarnDecorator(CropField* field , int capacity);
    int harvest();
    void rain();
    int getTotalCapacity();
    int getLeftOverCapacity();
    ~ExtraBarnDecorator();

};


#endif
