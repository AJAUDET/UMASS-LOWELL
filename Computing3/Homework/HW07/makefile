CC = g++
CFLAGS = -Wall -g
OBJECTS = Person.o

test:
	g++ Person.cpp test.cpp -o test -lboost_unit_test_framework

clean:
	rm -f $(OBJECTS) test