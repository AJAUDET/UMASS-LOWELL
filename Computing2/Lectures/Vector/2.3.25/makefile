CC = gcc
CFLAGS = -Wall -g
OBJECTS = main.o my_vector.o 

program: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o program

main.o:main.c 
	$(CC) $(CFLAGS) -c main.c 

my_vector.o:my_vector.c 
	$(CC) $(CFLAGS) -c my_vector.c 

clear:
	rm -f $(OBJECTS) program