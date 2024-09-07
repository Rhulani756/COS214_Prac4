

#ifndef PRAC_4_CROPFIELD_H
#define PRAC_4_CROPFIELD_H


#include "FarmUnit.h"
#include "SoilState.h"
#include "TruckObserver.h"
#include <string>
#include <vector>
class CropField :FarmUnit{
private:
    std::string cropType;
int storageCapacity;
int amountStored;
SoilState* soilState;
int baseYield;
std::vector<TruckObserver*> observers;
std::vector<FarmUnit*> units;


public:
   CropField(std::string crop, int capacity, SoilState* initialState);
   int getTotalCapacity() override;
   std::string getCropType() override;
    std::string getSoilStateName() override;
    virtual int harvest() = 0;
    virtual void rain() = 0;
    virtual int getLeftOverCapacity() = 0;
    virtual void increaseProduction() = 0;
   void attach(TruckObserver* observer);
   void detach(TruckObserver* observer);
   void notify();
   void add (FarmUnit* unit) override;
    void remove (FarmUnit* unit) override;
    FarmUnit* getChild(int index) override;
    std::string getName() override;  // Declare getName()
    std::vector<FarmUnit*> getUnits();

    SoilState* getSoilState() const;

    ~CropField();
};


#endif
