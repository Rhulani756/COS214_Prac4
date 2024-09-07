
#ifndef PRAC_4_BARN_H
#define PRAC_4_BARN_H


#include "FarmUnit.h"

class Barn : public FarmUnit {
private:
    int storageCapacity;  // Storage capacity provided by the barn
public:
    Barn(int capacity);
    int getTotalCapacity() override;
    std::string getCropType() override;
    std::string getSoilStateName() override;
    void add(FarmUnit* unit) override;
    void remove(FarmUnit* unit) override;
    FarmUnit* getChild(int index) override;
    ~Barn();
};

#endif
