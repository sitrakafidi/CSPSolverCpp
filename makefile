CXX=g++
CXXFLAGS=-g -Ofast
LDFLAGS=-std=c++11

TARGET=Main
HPP_FILE=$(wildcard src/solver/*.hpp) $(wildcard src/solver/constraints/*.hpp) $(wildcard src/solver/problems/*.hpp)
SRC_SOLVER=$(wildcard src/solver/*.cpp) $(wildcard src/solver/constraints/*.cpp) $(wildcard src/solver/problems/*.cpp)
OBJ_SOLVER=$(SRC_SOLVER:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ_SOLVER) 
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

Main.o: $(HPP_FILE)

.PHONY: clean

clean:
	-rm src/solver/*.o src/solver/constraints/*.o src/solver/problems/*.o Main 
