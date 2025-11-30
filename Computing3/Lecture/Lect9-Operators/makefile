CC = g++
CFLAGS = -Wall -g
OBJECTS = main.o money.o

program:$(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o money.exe

main.o: main.cpp 
	$(CC) $(CFLAGS) -c main.cpp 

money.o: money.cpp
	$(CC) $(CFLAGS) -c money.cpp

clean:
	rm -f $(OBJECTS) money.exe