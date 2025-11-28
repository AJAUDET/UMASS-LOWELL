CC = g++
CFLAGS = -Wall -g
OBJECTS = main.o Rational.o

program: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o rational.exe

main.o:main.cpp 
	$(CC) $(CFLAGS) -c main.cpp

Rational.o:Rational.cpp
	$(CC) $(CFLAGS) -c Rational.cpp

test:
	g++ Rational.cpp test.cpp -o test -lboost_unit_test_framework

clean:
	rm -f $(OBJECTS) rational.exe test