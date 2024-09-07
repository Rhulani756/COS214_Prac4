
#ifndef PRAC_4_ITERATOR_H
#define PRAC_4_ITERATOR_H

#include "FarmUnit.h"
class Iterator: public FarmUnit{
public:
Iterator();
FarmUnit* firstFarm();
FarmUnit* next();
bool isDone();
FarmUnit* currentFarm();
~Iterator();
};


#endif
