CC = gcc
CFLAGS = -Wall -g
OBJECTS = main.o queue.o 

program: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o program

main.o:main.c 
	$(CC) $(CFLAGS) -c main.c 

queue.o:queue.c 
	$(CC) $(CFLAGS) -c queue.c 

clean:
	rm -f $(OBJECTS) program