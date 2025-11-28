CC = gcc
CFLAGS = -Wall -g
OBJECTS = main.o

program: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o program

main.o:main.c 
	$(CC) $(CFLAGS) -c main.c 

clean:
	rm -f $(OBJECTS) program