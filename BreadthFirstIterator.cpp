#include "BreadthFirstIterator.h"

BreadthFirstIterator::BreadthFirstIterator(FarmUnit* root) : current(nullptr) {
    if (root) {
        farmQueue.push(root);  // Initialize the queue with the root farm unit
    }
}

FarmUnit* BreadthFirstIterator::firstFarm() {
    if (!farmQueue.empty()) {
        current = farmQueue.front();  // Get the first farm unit in the queue
        farmQueue.pop();  // Remove it from the queue
        return current;
    }
    return nullptr;
}

FarmUnit* BreadthFirstIterator::next() {
    if (!farmQueue.empty()) {
        current = farmQueue.front();  // Get the next farm unit in the queue
        farmQueue.pop();  // Remove it from the queue

        // Add all child farm units to the queue
        for (int i = 0; i < current->getChildCount(); i++) {
            farmQueue.push(current->getChild(i));
        }

        return current;
    }
    return nullptr;
}

bool BreadthFirstIterator::isDone() {
    return farmQueue.empty();  // Traversal is done if the queue is empty
}

FarmUnit* BreadthFirstIterator::currentFarm() {
    return current;  // Return the current farm being visited
}
