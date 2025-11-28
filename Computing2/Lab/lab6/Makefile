CC=gcc
CFLAGS=-Wall -g
OBJECTS=main.o my_string.o

program: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o program
test_defs.o:test_defs.c
	$(CC) $(CFLAGS) -c test_defs.c
unit_test: my_string.o unit_test.o test_defs.o
	$(CC) $(CFLAGS) -o unit_test unit_test.o test_defs.o my_string.o
main.o:main.c
	$(CC) $(CFLAGS) -c main.c 
my_string.o:my_string.c
	$(CC) $(CFLAGS) -c my_string.c
clean:
	rm -f *.o program
