# Executable name
EXECUTABLE = oasis

# Compiler
CXX = g++

# Default flags
CXXFLAGS = -std=c++17 -Wconversion -Wall -Werror -Wextra -pedantic

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:%.cpp=%.o)

# Object creation rule
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $*.cpp

# Debug build
debug: CXXFLAGS += -g3 -DDEBUG -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG
debug:
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(EXECUTABLE)_debug
.PHONY: debug

# Release build
release: CXXFLAGS += -O3 -DNDEBUG
release: $(EXECUTABLE)
.PHONY: release

# Executable
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)

# Clean
clean:
	rm -f *.o $(EXECUTABLE) $(EXECUTABLE)_debug
.PHONY: clean

all: debug release
.PHONY: all

# This Makefile was inspired by the EECS 281 Makefile
