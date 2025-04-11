CXX = g++
CXXFLAGS = -g -Isrc -Itests  

SOURCES = src/*.cpp tests/*.cpp main.cpp
EXECUTABLE = main

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CXX) $(CXXFLAGS) $^ -o $@

