CC = g++
CFLAGS = -Wall -g
OBJECTS = test.o 

program: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o point.exe

test.o:test.cpp 
	$(CC) $(CFLAGS) -c test.cpp 

clean:
	rm -f $(OBJECTS) point.exe