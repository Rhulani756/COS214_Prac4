
#ifndef PRAC_4_DEPHTFIRSTITERATOR_H
#define PRAC_4_DEPHTFIRSTITERATOR_H

#include "FarmUnit.h"
class DephtFirstIterator {
private:
  //  stack<FarmUnit*> stack;
    DephtFirstIterator(FarmUnit* root);
  FarmUnit* firstFarm();
  FarmUnit* next();
  bool isDone();
  FarmUnit* currentFarm();
};


#endif
