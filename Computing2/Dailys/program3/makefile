CC = gcc
CFLAGS = -Wall -g
OBJECTS = main.o filter.o 

program: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o program

main.o:main.c 
	$(CC) $(CFLAGS) -c main.c 

filter.o:filter.c 
	$(CC) $(CFLAGS) -c filter.c 

clean:
	rm -f $(OBJECTS) program