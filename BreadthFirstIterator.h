
#ifndef PRAC_4_BREADTHFIRSTITERATOR_H
#define PRAC_4_BREADTHFIRSTITERATOR_H

#include "Iterator.h"
#include <queue>

class BreadthFirstIterator: public Iterator{
private:
    std::queue<FarmUnit*> farmQueue;
    FarmUnit* current;
public:
        BreadthFirstIterator(FarmUnit* root);
        FarmUnit* firstFarm() override;
        FarmUnit* next() override;
        bool isDone() override;
        FarmUnit* currentFarm() override;


};


#endif
