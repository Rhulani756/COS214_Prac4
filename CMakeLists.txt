cmake_minimum_required(VERSION 3.27)
project(Prac_4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Prac_4
        Barn.cpp
        Barn.h
        BreadthFirstIterator.cpp
        BreadthFirstIterator.h
        CropField.cpp
        CropField.h
        CropFieldDecorator.cpp
        CropFieldDecorator.h
        DeliveryTruck.cpp
        DeliveryTruck.h
        DephtFirstIterator.cpp
        DephtFirstIterator.h
        DrySoil.cpp
        DrySoil.h
        ExtraBarnDecorator.cpp
        ExtraBarnDecorator.h
        FarmTraversalContext.cpp
        FarmTraversalContext.h
        FarmUnit.cpp
        FarmUnit.h
        FertilizerDecorator.cpp
        FertilizerDecorator.h
        FertilizerTruck.cpp
        FertilizerTruck.h
        FloodedSoil.cpp
        FloodedSoil.h
        FruitfulSoil.cpp
        FruitfulSoil.h
        Iterator.cpp
        Iterator.h
        Main.cpp
        SoilState.cpp
        SoilState.h
        TraversalContext.cpp
        TraversalContext.h
        TruckLogisticsManager.cpp
        TruckLogisticsManager.h
        TruckObserver.cpp
        TruckObserver.h
)
