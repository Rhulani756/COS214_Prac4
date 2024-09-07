
#ifndef PRAC_4_DEPHTFIRSTITERATOR_H
#define PRAC_4_DEPHTFIRSTITERATOR_H

#include "FarmUnit.h"
#include <stack>
class DephtFirstIterator {
private:
    std::stack<FarmUnit*> farmStack;
    FarmUnit* current;
public:
  DephtFirstIterator(FarmUnit* root);
  FarmUnit* firstFarm();
  FarmUnit* next();
  bool isDone();
  FarmUnit* currentFarm();
};


#endif
