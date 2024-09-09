#ifndef PRAC_4_DEPHTFIRSTITERATOR_H
#define PRAC_4_DEPHTFIRSTITERATOR_H

#include "Iterator.h"
#include <stack>

class DephtFirstIterator : public Iterator {
private:
    std::stack<FarmUnit*> farmStack;  // Stack for DFS traversal
    FarmUnit* current;  // Pointer to the current farm unit

public:
    explicit DephtFirstIterator(FarmUnit* root);  // Constructor

    FarmUnit* firstFarm() override;  // Return the first farm in DFS order
    FarmUnit* next() override;  // Move to the next farm in DFS order
    bool isDone() override;  // Check if traversal is complete
    FarmUnit* currentFarm() override;  // Return the current farm

    ~DephtFirstIterator() override = default;  // Destructor
};

#endif
