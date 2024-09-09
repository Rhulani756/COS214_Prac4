#include "DrySoil.h"
#include "ExtraBarnDecorator.h"
#include "FarmTraversalContext.h"
#include "FarmUnit.h"
#include "Barn.h"
#include "BreadthFirstIterator.h"
#include "CropField.h"
#include "CropFieldDecorator.h"
#include "DeliveryTruck.h"
#include "DephtFirstIterator.h"
#include "TruckObserver.h"
#include "FertilizerDecorator.h"
#include "FertilizerTruck.h"
#include "FloodedSoil.h"
#include "FruitfulSoil.h"
#include "Iterator.h"
#include "SoilState.h"
#include "TraversalContext.h"
#include "TruckLogisticsManager.h"

#include <iostream>
#include <cassert>

// Define a basic function to test each header file
void test_DrySoil() {
        // Create a DrySoil object
        DrySoil soil;

        // Test the getName method
        assert(soil.getName() == "Dry");
        std::cout << "DrySoil getName test passed." << std::endl;

        // Test the harvestCrops method with a base yield of 100
        int yield = soil.harvestCrops(100);
        assert(yield == 100);  // Since baseYield * 1 = 100
        std::cout << "DrySoil harvestCrops test passed." << std::endl;

        // Test the rain method, which should return a new FruitfulSoil
        SoilState* nextSoil = soil.rain();
        assert(nextSoil->getName() == "Fruitful");
        std::cout << "DrySoil rain transition to FruitfulSoil test passed." << std::endl;

        // Clean up the dynamically allocated FruitfulSoil object
        delete nextSoil;
    }

void test_CropField() {
    SoilState* soil = new DrySoil();  // Assuming SoilState has a default constructor
    CropField field("Wheat", 1000, soil);

    // Test getTotalCapacity
    assert(field.getTotalCapacity() == 1000);
    std::cout << "CropField getTotalCapacity test passed." << std::endl;

    // Test getCropType
    assert(field.getCropType() == "Wheat");
    std::cout << "CropField getCropType test passed." << std::endl;

    // Test getSoilStateName
    assert(field.getSoilStateName() == soil->getName());  // Assuming SoilState has a getName() method
    std::cout << "CropField getSoilStateName test passed." << std::endl;

    // Test harvest
    assert(field.harvest() );  // Assuming no crops are stored initially
    std::cout << "CropField harvest test passed." << std::endl;

    // Test getLeftOverCapacity
    assert(field.getLeftOverCapacity());
    std::cout << "CropField getLeftOverCapacity test passed." << std::endl;

    // Test add and remove methods
    FarmUnit* unit = new CropField("Corn", 500, soil);
    field.add(unit);

    // Test getName
    assert(field.getName() == "CropField");
    std::cout << "CropField getName test passed." << std::endl;

    // Clean up
    delete unit;
}

void test_FruitfulSoil() {
    // Create a FruitfulSoil object
    FruitfulSoil soil;

    // Test the getName method
    assert(soil.getName() == "Fruitful");
    std::cout << "FruitfulSoil getName test passed." << std::endl;

    // Test the harvestCrops method with a base yield of 100
    int yield = soil.harvestCrops(100);
    assert(yield == 300);  // Since baseYield * 3 = 300
    std::cout << "FruitfulSoil harvestCrops test passed." << std::endl;

    // Test the rain method, which should return a new FloodedSoil
    SoilState* nextSoil = soil.rain();
    assert(nextSoil->getName() == "Flooded");
    std::cout << "FruitfulSoil rain transition to FloodedSoil test passed." << std::endl;

    // Clean up the dynamically allocated FloodedSoil object
    delete nextSoil;
}
void test_FloodedSoil() {
    // Create a FloodedSoil object
    FloodedSoil soil;

    // Test the getName method
    assert(soil.getName() == "Flooded");
    std::cout << "FloodedSoil getName test passed." << std::endl;

    // Test the harvestCrops method with a base yield of 100
    int yield = soil.harvestCrops(100);
    assert(yield == 0);  // No crops can be harvested in flooded soil
    std::cout << "FloodedSoil harvestCrops test passed." << std::endl;

    // Test the rain method, which should return the same FloodedSoil state
    SoilState* nextSoil = soil.rain();
    assert(nextSoil == &soil);  // The state should not change
    std::cout << "FloodedSoil rain has no effect test passed." << std::endl;
}

void test_FertilizerDecorator() {
    // Create a CropField object
    SoilState* drySoil = new DrySoil();
    CropField* field = new CropField("Corn", 100, drySoil);

    // Decorate the field with FertilizerDecorator
    FertilizerDecorator* fertilizedField = new FertilizerDecorator(field, 100);

    // Test initial state
    assert(fertilizedField->getCropType() == "Corn");
    assert(fertilizedField->getTotalCapacity() == 100);
    assert(fertilizedField->getSoilStateName() == "Dry");
    std::cout << "Initial state tests passed." << std::endl;

    // Test harvest
    int harvestedAmount = fertilizedField->harvest();
    assert(harvestedAmount > 0);  // Ensure that some crops are harvested
    std::cout << "Harvest test passed." << std::endl;

    // Test increaseProduction
    fertilizedField->increaseProduction();
    int nextHarvestAmount = fertilizedField->harvest();
    assert(nextHarvestAmount > harvestedAmount);  // Ensure that production increased
    std::cout << "Increase production test passed." << std::endl;

    // Test rain method
    fertilizedField->rain();  // This may affect soil state, which could be tested further
    std::cout << "Rain method test passed." << std::endl;

    // Clean up
    delete fertilizedField;  // This also deletes the underlying CropField
}

void test_Barn() {
    // Create a Barn object with a specific capacity
    Barn barn(500);

    // Test the getTotalCapacity method
    assert(barn.getTotalCapacity() == 500);
    std::cout << "Barn getTotalCapacity test passed." << std::endl;

    // Test the getCropType method
    assert(barn.getCropType() == "None");  // Assuming default implementation returns "None"
    std::cout << "Barn getCropType test passed." << std::endl;

    // Test the getSoilStateName method
    assert(barn.getSoilStateName() == "Unknown");  // Assuming default implementation returns "Unknown"
    std::cout << "Barn getSoilStateName test passed." << std::endl;

    // Test the add method
    try {
        barn.add(nullptr);  // This should throw an exception based on the implementation
        std::cerr << "Barn add test failed: Expected exception not thrown." << std::endl;
    } catch (const std::logic_error& e) {
        std::cout << "Barn add test passed." << std::endl;
    }

    // Test the remove method
    try {
        barn.remove(nullptr);  // This should throw an exception based on the implementation
        std::cerr << "Barn remove test failed: Expected exception not thrown." << std::endl;
    } catch (const std::logic_error& e) {
        std::cout << "Barn remove test passed." << std::endl;
    }

    // Test the getChild method
    try {
        barn.getChild(0);  // This should throw an exception based on the implementation
        std::cerr << "Barn getChild test failed: Expected exception not thrown." << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Barn getChild test passed." << std::endl;
    }
}

void test_ExtraBarnDecorator() {
    // Create a CropField object
    SoilState* drySoil = new DrySoil();
    CropField* field = new CropField("Wheat", 100, drySoil);

    // Decorate the field with ExtraBarnDecorator to add extra capacity
    ExtraBarnDecorator* extraBarnField = new ExtraBarnDecorator(field, 50);

    // Test initial state
    assert(extraBarnField->getCropType() == "Wheat");
    assert(extraBarnField->getTotalCapacity() == 150);  // Original 100 + 50 extra
    assert(extraBarnField->getSoilStateName() == "Dry");
    std::cout << "Initial state tests passed." << std::endl;

    // Test harvest
    int harvestedAmount = extraBarnField->harvest();
    assert(harvestedAmount > 0);  // Ensure that some crops are harvested
    std::cout << "Harvest test passed." << std::endl;

    // Test leftover capacity
    int leftOverCapacity = extraBarnField->getLeftOverCapacity();
    assert(leftOverCapacity == 150 - harvestedAmount);  // Check that leftover capacity includes extra barn capacity
    std::cout << "Leftover capacity test passed." << std::endl;

    // Test rain method
    extraBarnField->rain();  // This may affect soil state, which could be tested further
    std::cout << "Rain method test passed." << std::endl;

    // Clean up
    delete extraBarnField;  // This also deletes the underlying CropField
}



int main() {
    std::cout<<"=======================================";
    std::cout<<"\n";
    std::cout<<"DrySoil test :";
    test_DrySoil();
    std::cout<<"=======================================";
    std::cout<<"\n";
    std::cout<<"FruitfulSoil test :";
    test_FruitfulSoil();
    std::cout<<"=======================================";
    std::cout<<"\n";
    std::cout<<"FloodedSoil test :";
    test_FloodedSoil();
    std::cout<<"=======================================";
    std::cout<<"\n";

    test_Barn();
    std::cout<<"=======================================";
    std::cout<<"\n";

    test_CropField();
    std::cout<<"=======================================";
    std::cout<<"\n";

    std::cout<<"=======================================";
    std::cout<<"\n";

    test_FertilizerDecorator();

    test_ExtraBarnDecorator();
    // Add calls to other test functions here...

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
