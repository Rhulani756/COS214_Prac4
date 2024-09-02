# Makefile for Hello World C++ project

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g

# Target executable
TARGET = main

# Source files
SRC = main.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Default target: compile the program
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJ)
	$(CXX) -o $@ $(OBJ)

# Compile the source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean up build files
clean:
	rm -f $(TARGET) $(OBJ)

# Phony targets to avoid conflicts with files
.PHONY: all run clean
