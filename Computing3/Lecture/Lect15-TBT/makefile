CC = g++
CFLAGS = -Wall -g
OBJECTS = main.o LinkedList.o

program: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o linked.exe

main.o:main.cpp 
	$(CC) $(CFLAGS) -c main.cpp

LinkedList.o:LinkedList.cpp
	$(CC) $(CFLAGS) -c LinkedList.cpp

clean:
	rm -f $(OBJECTS) linked.exe