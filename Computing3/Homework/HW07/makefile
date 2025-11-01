CC = g++
CFLAGS = -Wall -g
OBJECTS = Person.o

test:
	g++ Person.cpp test.cpp -o test \
    -I/opt/homebrew/include \
    -L/opt/homebrew/lib \
    -lboost_unit_test_framework \
    -std=c++17

clean:
	rm -f $(OBJECTS) test