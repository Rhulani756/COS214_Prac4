#ifndef PRAC_4_BREADTHFIRSTITERATOR_H
#define PRAC_4_BREADTHFIRSTITERATOR_H

#include "Iterator.h"
#include <queue>

class BreadthFirstIterator : public Iterator {
private:
    std::queue<FarmUnit*> farmQueue;  // Queue for BFS traversal
    FarmUnit* current;  // Pointer to the current farm unit

public:
    explicit BreadthFirstIterator(FarmUnit* root);  // Constructor

    FarmUnit* firstFarm() override;  // Return the first farm in the BFS order
    FarmUnit* next() override;  // Move to the next farm in BFS order
    bool isDone() override;  // Check if traversal is complete
    FarmUnit* currentFarm() override;  // Return the current farm

    ~BreadthFirstIterator() override = default;  // Destructor
};

#endif
