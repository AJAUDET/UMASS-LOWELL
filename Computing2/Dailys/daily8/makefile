CC = gcc
CFLAGS = -Wall -g
OBJECTS = main.o priority_queue.o 

program: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o program

main.o:main.c 
	$(CC) $(CFLAGS) -c main.c 

priority_queue.o:priority_queue.c 
	$(CC) $(CFLAGS) -c priority_queue.c 

clean:
	rm -f $(OBJECTS) program