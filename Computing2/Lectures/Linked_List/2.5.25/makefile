CC = gcc
CFLAGS = -Wall -g
OBJECTS = main.o file1.o 

program: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o program

main.o:main.c 
	$(CC) $(CFLAGS) -c main.c 

file1.o:file1.c 
	$(CC) $(CFLAGS) -c file1.c 

clean:
	rm -f *.0 program