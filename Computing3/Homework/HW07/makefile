CC = g++
CFLAGS = -Wall -g
OBJECTS = Person.o Vehicle.o

test:
	g++ Person.cpp Vehicle.cpp test.cpp -o test -lboost_unit_test_framework

clean:
	rm -f $(OBJECTS) test