CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

SOURCES = $(wildcard *.cpp)
EXECUTABLES = $(SOURCES:.cpp=)

.PHONY: all clean

all: $(EXECUTABLES)

%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLES)
