#ifndef PRAC_4_BARN_H
#define PRAC_4_BARN_H

#include "FarmUnit.h"

class Barn : public FarmUnit {
private:
    int storageCapacity;  // Storage capacity provided by the barn

public:
    // Constructor to initialize Barn with a specific capacity
    Barn(int capacity);

    // Override pure virtual methods
    void add(FarmUnit* unit) override;
    void remove(FarmUnit* unit) override;
    FarmUnit* getChild(int index) override;
    int getChildCount() override;
    std::string getName() override;
    int getTotalCapacity() override;
    std::string getCropType() override;
    std::string getSoilStateName() override;
    int harvest() override;

    // Destructor
    ~Barn() override;
};

#endif // PRAC_4_BARN_H
