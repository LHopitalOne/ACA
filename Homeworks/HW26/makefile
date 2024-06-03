CXX := g++
CXXFLAGS := -Wall -g -std=c++17
TARGET := main

SRC := $(wildcard *.cpp)
OBJ := $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(TARGET) $(OBJ)

.PHONY: all clean
