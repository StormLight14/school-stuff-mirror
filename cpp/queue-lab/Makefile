CXX = g++
CXXFLAGS = -std=c++17

# Define the target executable and source file
TARGET = main
SRC = main.cpp

# Default target to build
all: $(TARGET)

# Rule to build the target
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Clean up build artifacts
clean:
	rm -f $(TARGET)
