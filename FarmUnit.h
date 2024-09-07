
#ifndef PRAC_4_FARMUNIT_H
#define PRAC_4_FARMUNIT_H

#include <iostream>
class FarmUnit {
public:
    FarmUnit();
    void add(FarmUnit* unit);
    void remove(FarmUnit* unit);
    FarmUnit* getChild(int index);
    std::string getName();
    ~FarmUnit();
};


#endif
