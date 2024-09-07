

#ifndef PRAC_4_TRAVERSALCONTEXT_H
#define PRAC_4_TRAVERSALCONTEXT_H

#include "Iterator.h"
class TraversalContext{
private:
    Iterator* iterator;
public:
    TraversalContext();  // Constructor
    void setTraversalStrategy(Iterator* newIterator);  // Set a new traversal strategy
    void traverseFarms();  // Traverse farms using the current strategy
    ~TraversalContext();  // Destructor
};


#endif
