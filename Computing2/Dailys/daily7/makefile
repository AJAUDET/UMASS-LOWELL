CC = gcc
CFLAGS = -Wall -g
OBJECTS = main.o stack.o 

program: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o program

main.o:main.c 
	$(CC) $(CFLAGS) -c main.c 

stack.o:stack.c 
	$(CC) $(CFLAGS) -c stack.c 

clean:
	rm -f $(OBJECTS) program