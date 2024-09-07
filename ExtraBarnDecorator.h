

#ifndef PRAC_4_EXTRABARNDECORATOR_H
#define PRAC_4_EXTRABARNDECORATOR_H

#include "CropFieldDecorator.h"
class ExtraBarnDecorator: public CropFieldDecorator {
private:
    int extraCapacity;
public:
    ExtraBarnDecorator(CropField* field, int capacity);  // Constructor to add extra capacity
    int harvest() override;  // Harvest crops as usual
    void rain() override;  // Rain as usual
    int getTotalCapacity() override;  // Return total capacity including the extra barn capacity
    int getLeftOverCapacity() override;  // Return leftover capacity including the extra barn capacity
    ~ExtraBarnDecorator();  // Destructor

};


#endif
