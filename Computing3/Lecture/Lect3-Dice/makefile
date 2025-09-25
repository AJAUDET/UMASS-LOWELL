CC = g++
CFLAGS = -Wall -g
OBJECTS = main.o

program: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o dice.exe

main.o:main.cpp 
	$(CC) $(CFLAGS) -c main.cpp 

clean:
	rm -f $(OBJECTS) dice.exe