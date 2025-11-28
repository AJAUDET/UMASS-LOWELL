CC = g++
CFLAGS = -Wall -g
OBJECTS = main.o 
TEST_OBJECT = test.o

program: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o money.exe

test_program: $(TEST_OBJECT)
	$(CC) $(CFLAGS) $(TEST_OBJECT) -o test_progam.exe

main.o:main.cpp 
	$(CC) $(CFLAGS) -c main.cpp 

test.o:test.cpp
	$(CC) $(CFLAGS) -c test.cpp

clean:
	rm -f $(OBJECTS) money.exe