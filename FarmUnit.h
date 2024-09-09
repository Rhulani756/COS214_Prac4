//Pure Virtual
#ifndef PRAC_4_FARMUNIT_H
#define PRAC_4_FARMUNIT_H

#include <iostream>
class FarmUnit {
public:
    FarmUnit();
    virtual void add(FarmUnit* unit)= 0;
    virtual void remove(FarmUnit* unit)= 0;
    virtual FarmUnit* getChild(int index) = 0;
    virtual std::string getName()= 0;
    virtual ~FarmUnit()= default;

    int getChildCount();
};


#endif
