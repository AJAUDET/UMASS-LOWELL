CC = gcc
CFLAGS = -Wall -g 
OBJECTS = main.o vector.o 

program: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o program

main.o:main.c
	$(CC) $(CFLAGS) -c main.c 

vector.o:vector.c 
	$(CC) $(CFLAGS) -c vector.c 