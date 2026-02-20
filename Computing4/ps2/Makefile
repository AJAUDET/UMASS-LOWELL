CC = g++
CFLAGS = --std=c++20 -Wall -Werror -pedantic -g
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
BOOSTLIB = -lboost_unit_test_framework

DEPS = PTree.hpp
OBJECTS = PTree.cpp
PROGRAM = PTree

.PHONY: all clean lint


all: $(PROGRAM)

# Wildcard recipe to make .o files from corresponding .cpp file
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

$(PROGRAM): main.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB) $(BOOSTLIB)

clean:
	rm *.o $(PROGRAM)

lint:
	cpplint *.cpp *.hpp