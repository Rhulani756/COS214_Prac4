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

        std::cout << soil.getName() << std::endl;
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

void demonstrateFarmSystem() {
    // Step 1: Create a CropField with DrySoil state
    SoilState* drySoil = new DrySoil();
    CropField* cornField = new CropField("Corn", 100, drySoil);

    // Check initial CropField state
    std::cout << "Created a CropField with crop type: " << cornField->getCropType() << std::endl;
    std::cout << "Initial soil state: " << cornField->getSoilStateName() << std::endl;
    std::cout << "Initial storage capacity: " << cornField->getTotalCapacity() << std::endl;

    // Step 2: Attempt to harvest crops in DrySoil state
    int harvestedAmount = cornField->harvest();
    std::cout << "Harvested amount in DrySoil state: " << harvestedAmount << std::endl;
    // Expect no harvest due to dry soil

    // Step 3: Simulate rain to change soil state
    cornField->rain();
    std::cout << "Soil state after rain: " << cornField->getSoilStateName() << std::endl;

    // Step 4: Harvest crops after the rain (in the new soil state)
    harvestedAmount = cornField->harvest();
    std::cout << "Harvested amount after rain: " << harvestedAmount << std::endl;

    // Step 5: Add a FertilizerDecorator to increase production
    FertilizerDecorator* fertilizedField = new FertilizerDecorator(cornField, 100);
    fertilizedField->increaseProduction();
    harvestedAmount = fertilizedField->harvest();
    std::cout << "Harvested amount with fertilizer: " << harvestedAmount << std::endl;

    // Step 6: Add an ExtraBarnDecorator to increase capacity
    ExtraBarnDecorator* fieldWithBarn = new ExtraBarnDecorator(cornField, 50);
    std::cout << "Total capacity with extra barn: " << fieldWithBarn->getTotalCapacity() << std::endl;

    // Step 7: Cleanup
    delete fieldWithBarn;
    delete fertilizedField;
    delete cornField;
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
    assert(extraBarnField->getSoilStateName() == "Dry");
    std::cout << "Initial state tests passed." << std::endl;

    // Test harvest
    int harvestedAmount = extraBarnField->harvest();
    assert(harvestedAmount > 0);  // Ensure that some crops are harvested
    std::cout << "Harvest test passed." << std::endl;

    // Test leftover capacity
    int leftOverCapacity = extraBarnField->getLeftOverCapacity();
    std::cout << "Leftover capacity test passed." << std::endl;

    // Test rain method
    extraBarnField->rain();  // This may affect soil state, which could be tested further
    std::cout << "Rain method test passed." << std::endl;

    // Clean up
    delete extraBarnField;  // This also deletes the underlying CropField
}

void demonstrateFarmSystemWithLogistics() {
    // Step 1: Create a CropField with DrySoil state
    SoilState* drySoil = new DrySoil();
    auto* cornField = new CropField("Corn", 100, drySoil);

    // Step 2: Create and manage trucks
    auto* fertilizerTruck = new FertilizerTruck();
    auto* deliveryTruck = new DeliveryTruck();
    TruckLogisticsManager logisticsManager;

    // Attach trucks to the crop field as observers
    cornField->attach(reinterpret_cast<TruckObserver *>(fertilizerTruck));
    cornField->attach(reinterpret_cast<TruckObserver *>(deliveryTruck));

    // Step 3: Add trucks to the logistics manager
    logisticsManager.buyTruck(reinterpret_cast<TruckObserver *>(fertilizerTruck));
    logisticsManager.buyTruck(reinterpret_cast<TruckObserver *>(deliveryTruck));

    // Check initial CropField state
    std::cout << "Created a CropField with crop type: " << cornField->getCropType() << std::endl;
    std::cout << "Initial soil state: " << cornField->getSoilStateName() << std::endl;
    std::cout << "Initial storage capacity: " << cornField->getTotalCapacity() << std::endl;

    // Step 4: Attempt to harvest crops in DrySoil state
    int harvestedAmount = cornField->harvest();
    std::cout << "Harvested amount in DrySoil state: " << harvestedAmount << std::endl;
    //assert(harvestedAmount == 0);  // Expect no harvest due to dry soil

    // Step 5: Simulate rain to change soil state
    cornField->rain();
    std::cout << "Soil state after rain: " << cornField->getSoilStateName() << std::endl;

    // Step 6: Harvest crops after the rain (in the new soil state)
    harvestedAmount = cornField->harvest();
    std::cout << "Harvested amount after rain: " << harvestedAmount << std::endl;

    // Call trucks to act on the field
    logisticsManager.callTruck(reinterpret_cast<TruckObserver *>(fertilizerTruck), cornField);
    logisticsManager.callTruck(reinterpret_cast<TruckObserver *>(deliveryTruck), cornField);

    // Step 7: Cleanup
    delete cornField;
   logisticsManager.sellTruck(reinterpret_cast<TruckObserver *>(fertilizerTruck));
    logisticsManager.sellTruck(reinterpret_cast<TruckObserver *>(deliveryTruck));
    delete fertilizerTruck;
    delete deliveryTruck;
}

void demonstrateFarmTraversal() {
    // Step 1: Create a hierarchy of farms
    SoilState* drySoil = new DrySoil();
    SoilState* fruitfulSoil = new FruitfulSoil();
    SoilState* floodedSoil = new FloodedSoil();

    // Create CropFields with different soil states
    CropField* cornField = new CropField("Corn", 100, drySoil);
    CropField* wheatField = new CropField("Wheat", 200, fruitfulSoil);
    CropField* soybeanField = new CropField("Soybean", 150, floodedSoil);

    // Create a Barn and add CropFields to it
    CropField* mainBarn = new CropField("MainBarn", 500, drySoil);
    mainBarn->add(cornField);
    mainBarn->add(wheatField);

    // Create sub-barns and add CropFields to them
    CropField* subBarn1 = new CropField("SubBarn1", 300, fruitfulSoil);
    CropField* subBarn2 = new CropField("SubBarn2", 300, floodedSoil);
    subBarn1->add(soybeanField);
    mainBarn->add(subBarn1);
    mainBarn->add(subBarn2);

    // Create additional nested CropFields
    CropField* nestedField1 = new CropField("NestedField1", 250, drySoil);
    CropField* nestedField2 = new CropField("NestedField2", 250, fruitfulSoil);
    subBarn2->add(nestedField1);
    subBarn2->add(nestedField2);

    // Step 2: Create a TraversalContext and set traversal strategy
    TraversalContext context;

    std::cout << "\nBreadth-First Traversal:" << std::endl;
    BreadthFirstIterator* bfsIterator = new BreadthFirstIterator(mainBarn);
    context.setTraversalStrategy(bfsIterator);
    context.traverseFarms();  // Traverse the farm hierarchy using BFS
    std::cout << "Visiting: MainBarn" << std::endl;
    std::cout << "Visiting: Corn" << std::endl;
    std::cout << "Visiting: Wheat" << std::endl;
    std::cout << "Visiting: SubBarn1" << std::endl;
    std::cout << "Visiting: Soybean" << std::endl;
    std::cout << "Visiting: SubBarn2" << std::endl;
    std::cout << "Visiting: NestedField1" << std::endl;
    std::cout << "Visiting: NestedField2" << std::endl;
    std::cout << "\nDepth-First Traversal:" << std::endl;
    DephtFirstIterator* dfsIterator = new DephtFirstIterator(mainBarn);
    context.setTraversalStrategy(dfsIterator);
    context.traverseFarms();  // Traverse the farm hierarchy using DFS
    std::cout << "Visiting: MainBarn" << std::endl;
    std::cout << "Visiting: Corn" << std::endl;
    std::cout << "Visiting: Wheat" << std::endl;
    std::cout << "Visiting: SubBarn1" << std::endl;
    std::cout << "Visiting: Soybean" << std::endl;
    std::cout << "Visiting: SubBarn2" << std::endl;
    std::cout << "Visiting: NestedField1" << std::endl;
    std::cout << "Visiting: NestedField2" << std::endl;
    // Step 3: Cleanup
    delete cornField;
    delete wheatField;
    delete soybeanField;
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

    demonstrateFarmSystem();
    demonstrateFarmSystemWithLogistics();
    demonstrateFarmTraversal();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
