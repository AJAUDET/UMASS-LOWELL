CC = gcc
CFLAGS = -Wall -g
OBJECTS = main.o my_string.o generic_vector.o avl_tree.o

program: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o program

main.o:main.c 
	$(CC) $(CFLAGS) -c main.c 

my_string.o:my_string.c 
	$(CC) $(CFLAGS) -c my_string.c

generic_vector.o:generic_vector.c 
	$(CC) $(CFLAGS) -c generic_vector.c

avl_tree.o:avl_tree.c 
	$(CC) $(CFLAGS) -c avl_tree.c 

clean:
	rm -f $(OBJECTS) program