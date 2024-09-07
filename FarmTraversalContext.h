
#ifndef PRAC_4_FARMTRAVERSALCONTEXT_H
#define PRAC_4_FARMTRAVERSALCONTEXT_H

#include "Iterator.h"
class FarmTraversalContext: public Iterator{
private:
    Iterator* iterator;
public:
    FarmTraversalContext();
    void setTraversalStratagy(Iterator* newIterator);
    void traverseFarms();
    ~FarmTraversalContext();
};


#endif
