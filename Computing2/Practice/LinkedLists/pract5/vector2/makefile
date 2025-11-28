CC = gcc
CFLAGS = -Wall -g
OBJECTS = main.o vector.o

main.o:main.c
	$(CC) $(CFLAGS) -c main.c
vector.o:vector.c
	$(CC) $(CFLAGS) -o vector.c
program: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o program
clean:
	rm -f $(OBJECTS) program
