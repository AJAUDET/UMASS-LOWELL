CC = gcc
CFLAGS = -Wall -g
OBJECTS = main.o generic_vector.o 

program: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o program

main.o:main.c 
	$(CC) $(CFLAGS) -c main.c 

generic_vector.o:generic_vector.c 
	$(CC) $(CFLAGS) -c generic_vector.c 

clean:
	rm -f $(OBJECTS) program