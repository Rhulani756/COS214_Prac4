// DephtFirstIterator.cpp
#include "DephtFirstIterator.h"

DephtFirstIterator::DephtFirstIterator(FarmUnit* root) {
    if (root) {
        farmStack.push(root);  // Initialize the stack with the root farm unit
    }
}

// Returns the first farm unit and pops it off the stack
FarmUnit* DephtFirstIterator::firstFarm() {
    if (!farmStack.empty()) {
        current = farmStack.top();
        farmStack.pop();
        return current;
    }
    return nullptr;
}

// Moves to the next farm unit in depth-first order
FarmUnit* DephtFirstIterator::next() {
    if (!farmStack.empty()) {
        current = farmStack.top();  // Get the next farm unit in the stack
        farmStack.pop();  // Remove it from the stack

        // Push all child farm units onto the stack (in reverse order for correct DFS)
        for (int i = current->getChildCount() - 1; i >= 0; --i) {
            farmStack.push(current->getChild(i));
        }

        return current;
    }
    return nullptr;  // If stack is empty, return nullptr
}

// Checks if the stack is empty, meaning the traversal is done
bool DephtFirstIterator::isDone() {
    return farmStack.empty();
}

// Returns the current farm being traversed
FarmUnit* DephtFirstIterator::currentFarm() {
    return current;
}
