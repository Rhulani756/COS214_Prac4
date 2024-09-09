#ifndef PRAC_4_CROPFIELD_H
#define PRAC_4_CROPFIELD_H

#include "FarmUnit.h"
#include "SoilState.h"
#include "TruckObserver.h"
#include <string>
#include <vector>

class CropField : public FarmUnit {
private:
    std::string cropType;
    int storageCapacity;
    int amountStored;
    SoilState* soilState;
    int baseYield;
    std::vector<TruckObserver*> observers;
    std::vector<FarmUnit*> units;

public:
    // Constructor to initialize the CropField with crop type, capacity, and initial soil state
    CropField(std::string crop, int capacity, SoilState* initialState);

    // Override pure virtual methods from FarmUnit
    virtual int getTotalCapacity();
    std::string getCropType();
    std::string getSoilStateName();
    virtual int harvest();
    void rain();  // Not virtual because CropField doesn't need further specialization

    // Observer pattern methods for truck notifications
    void attach(TruckObserver* observer);
    void detach(TruckObserver* observer);
    void notify();

    // Composite pattern methods - CropField is a leaf node, so these are not applicable
    void add(FarmUnit* unit) override;
    void remove(FarmUnit* unit) override;
    FarmUnit* getChild(int index) override;
    std::string getName() override;  // Return the name of this unit (e.g., "CropField")

    SoilState* getSoilState() const;

    int getBaseYield();
    void setBaseYield(int yield);

    // Destructor to clean up resources
    ~CropField();
};

#endif // PRAC_4_CROPFIELD_H
