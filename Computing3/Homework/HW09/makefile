CXX = g++
CXXFLAGS = -std=c++20 -Wall -Werror -pedantic -g

all: test

test: PFArrayD.o test.o
	$(CXX) $(CXXFLAGS) PFArrayD.o test.o -o test -lboost_unit_test_framework

PFArrayD.o: PFArrayD.cpp PFArrayD.hpp OutOfRange.hpp
	$(CXX) $(CXXFLAGS) -c PFArrayD.cpp

test.o: test.cpp PFArrayD.hpp OutOfRange.hpp
	$(CXX) $(CXXFLAGS) -c test.cpp

clean:
	rm -f *.o test