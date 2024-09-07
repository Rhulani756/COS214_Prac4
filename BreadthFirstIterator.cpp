// BreadthFirstIterator.cpp
#include "BreadthFirstIterator.h"

BreadthFirstIterator::BreadthFirstIterator(FarmUnit* root) {
    if (root) {
        farmQueue.push(root);  // Initialize the queue with the root farm unit
    }
}

FarmUnit* BreadthFirstIterator::firstFarm() {
    if (!farmQueue.empty()) {
        current = farmQueue.front();
        farmQueue.pop();  // Remove the first farm unit from the queue
        return current;
    }
    return nullptr;
}

FarmUnit* BreadthFirstIterator::next() {
    if (!farmQueue.empty()) {
        current = farmQueue.front();  // Get the next farm unit in the queue
        farmQueue.pop();  // Remove it from the queue

        // Add all child farm units to the queue
        for (int k = 0; k < current->getChildCount(); k++) {
            farmQueue.push(current->getChild(k));
        }

        return current;
    }
    return nullptr;
}

bool BreadthFirstIterator::isDone() {
    return farmQueue.empty();
}

FarmUnit* BreadthFirstIterator::currentFarm() {
    return current;
}
