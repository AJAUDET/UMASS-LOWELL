CC = gcc
CFLAGS = -Wall -g
OBJECTS = main.o date.o 

program: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o program

main.o:main.c 
	$(CC) $(CFLAGS) -c main.c 

date.o:date.c 
	$(CC) $(CFLAGS) -c date.c 

clear:
	rm -f *.0 program