CC = gcc
CFLAGS = -Wall -g
OBJECTS = main.o bit_flags.o 

program: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o program

main.o:main.c
	$(CC) $(CFLAGS) -c main.c 

bit_flags.o:bit_flags.c
	$(CC) $(CFLAGS) -c bit_flags.c 

clean:
	rm -f $(OBJECTS) program