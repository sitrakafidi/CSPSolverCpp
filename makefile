CXX=g++
CXXFLAGS=-g -Ofast
LDFLAGS=-std=c++11

TARGET= Main
HPP_FILE=$(wildcard src/solver/*.hpp) $(wildcard src/constraints/*.hpp) $(wildcard src/problems/*.hpp)
SRC_SOLVER= $(wildcard src/solver/*.cpp) $(wildcard src/constraints/*.cpp) $(wildcard src/problems/*.cpp)
OBJ_SOLVER=$(SRC_SOLVER:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ_SOLVER) 
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS) $(LDFLAGS)

Main.o: $(HPP_FILE)
#Test.o: $(HPP_FILE)

.PHONY: clean

clean:
	-rm src/solver/*.o src/constraints/*.o src/problems/*.o Main
