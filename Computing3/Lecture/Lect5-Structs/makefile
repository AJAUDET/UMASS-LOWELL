CC = g++
CFLAGS = -Wall -g
OBJECTS = main.o

program: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o struct.exe

main.o:main.cpp 
	$(CC) $(CFLAGS) -c main.cpp 

clean:
	rm -f $(OBJECTS) struct.exe