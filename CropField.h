

#ifndef PRAC_4_CROPFIELD_H
#define PRAC_4_CROPFIELD_H

#include <iostream>
#include <vector>
#include "FarmUnit.h"
#include "SoilState.h"
#include "TruckObserver.h"
class CropField {
private:
    std::string cropType;
int storageCapacity;
int amountStored;
SoilState* soilState;
int baseYield;
std::vector<TruckObserver*> observer;
std::vector<FarmUnit*> units;


public:
   CropField();
   int getTotalCapacity();
   std::string getCropType();
   std::string getSoilTypeName();
   int harvest();
   void rain();
   int getLeftOverCapacity();
   void increaseProduction();
   void attach(TruckObserver* observer);
   void detach(TruckObserver* observer);
   void notify();
   void add (FarmUnit* unit);
    //void remove (FarmUnit* unit);
    FarmUnit* getChild(int index);
    std::string getName();
    std::vector<FarmUnit*> getUnits();
    ~CropField();
};


#endif
