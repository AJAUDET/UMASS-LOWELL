CC = g++
CFLAGS = -Wall -g
OBJECTS = DynamicStringArray.o

test:
	g++ DynamicStringArray.cpp test.cpp -o test -lboost_unit_test_framework

clean:
	rm -f $(OBJECTS) DynamicStringArray.exe test