

#ifndef PRAC_4_TRAVERSALCONTEXT_H
#define PRAC_4_TRAVERSALCONTEXT_H

#include "Iterator.h"
class TraversalContext : public Iterator{
public:
    void setTraversalStrategy(Iterator* newIterator);
    void traverseFarms();
    ~TraversalContext();
};


#endif
