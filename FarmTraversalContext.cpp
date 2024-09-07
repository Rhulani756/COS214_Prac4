// FarmTraversalContext.cpp
#include "FarmTraversalContext.h"
#include <iostream>

FarmTraversalContext::FarmTraversalContext() : iterator(nullptr) {}

// Set a new traversal strategy for farm traversal
void FarmTraversalContext::setTraversalStratagy(Iterator* newIterator) {
    if (iterator) {
        delete iterator;  // Clean up the previous iterator if it exists
    }
    iterator = newIterator;  // Set the new traversal strategy
}

// Traverse farms using the current iterator strategy
void FarmTraversalContext::traverseFarms() {
    if (!iterator) {
        std::cout << "No traversal strategy set!" << std::endl;
        return;
    }

    // Traverse the farms using the chosen strategy
    for (FarmUnit* farm = iterator->firstFarm(); !iterator->isDone(); farm = iterator->next()) {
        if (farm) {
            std::cout << "Visiting farm: " << farm->getName() << std::endl;
        }
    }
}

// Destructor to clean up the iterator
FarmTraversalContext::~FarmTraversalContext() {
    delete iterator;  // Ensure the current iterator is properly cleaned up
}
