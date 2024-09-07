
#ifndef PRAC_4_ITERATOR_H
#define PRAC_4_ITERATOR_H

#include "FarmUnit.h"
class Iterator{
public:
Iterator();
virtual  FarmUnit* firstFarm()=0;
    virtual FarmUnit* next()=0;
    virtual bool isDone()=0;
    virtual FarmUnit* currentFarm()=0;
    virtual ~Iterator();
};


#endif
