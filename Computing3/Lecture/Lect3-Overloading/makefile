CC = g++
CFLAGS = -Wall -g
OBJECTS = main.o

program: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o overload.exe

main.o:main.cpp 
	$(CC) $(CFLAGS) -c main.cpp 

clean:
	rm -f $(OBJECTS) overload.exe