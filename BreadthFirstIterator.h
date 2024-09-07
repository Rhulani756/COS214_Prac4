
#ifndef PRAC_4_BREADTHFIRSTITERATOR_H
#define PRAC_4_BREADTHFIRSTITERATOR_H

#include "FarmUnit.h"
class BreadthFirstIterator {
private:
        //  queue<FarmUnit*> queue;
public:
        BreadthFirstIterator(FarmUnit* root);
        FarmUnit* firstFarm();
        FarmUnit* next();
        bool isDone();
        FarmUnit* currentFarm();


};


#endif
