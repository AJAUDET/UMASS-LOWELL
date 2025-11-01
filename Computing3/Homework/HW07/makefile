CC = g++
CFLAGS = -Wall -g
OBJECTS = Person.o

test:
	g++ Person.cpp test.cpp -o test -lboost_unit_test_framework -L/opt/homebrew/lib

clean:
	rm -f $(OBJECTS) test